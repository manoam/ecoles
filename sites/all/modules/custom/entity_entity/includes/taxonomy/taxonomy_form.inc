<?php

function _taxonomy_load_form($form, &$form_state, $tid) {

    if ($tid != NULL && $tid != 0) {

        try {

            $tag = new WdTaxonomyTermWrapper($tid);

            if ($tag != NULL) {

                $form_state['tid'] = $tid;

                $form['taxonomy'] = array(
                    '#type' => 'fieldset',
                    '#title' => t('Taxonomy : ' . $tag->getBundle()),
                );

                $form['taxonomy']['name'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Nom : '),
                    '#default_value' => $tag->getName(),
                );

                switch ($tag->getBundle()) {

                    case 'classe':

                        // ampiana niveau ilay izy raha class no miseho
                        $option = _get_taxonomy_term('niveau');
                        $class = new ClasseTaxonomyTermWrapper($tid);
                        $form['taxonomy']['niveau'] = array(
                            '#type' => 'select',
                            '#title' => t('Niveau consernant : '),
                            '#options' => $option,
                            '#default_value' => $class->getNiveau()->tid,
                            '#attributes' => array('class' => array('sexe_select')),
                        );

                        break;
                    case 'niveau':

                        // ampiana ity indray raha niveau
                        $niveau = new NiveauTaxonomyTermWrapper($tid);
                        $form['taxonomy']['niveau'] = array(
                            '#type' => 'textfield',
                            '#title' => t('Code pour l\'import excel ou csv : '),
                            '#default_value' => $niveau->getCode(),
                        );

                        break;
                    case 'taompianarana':

                        module_load_include('php', 'wrappers_custom', 'includes/taxonomy_term/TaompianaranaTaxonomyTermWrapper');
                        // ampiana ity indray raha niveau
                        $taompianarana = new TaompianaranaTaxonomyTermWrapper($tid);
                        
                        $form['taxonomy']['start_date'] = array(
                            '#type' => 'textfield',
                            '#title' => t('Date debut de l\'année scolaire : '),
                            '#default_value' => date('d - M - Y', $taompianarana->getStartDate()),
                        );
                        
                        $form['taxonomy']['end_date'] = array(
                            '#type' => 'textfield',
                            '#title' => t('Date fin de l\'année scolaire : '),
                            '#default_value' => date('d - M - Y', $taompianarana->getEndDate()),
                        );

                        break;
                    
                    case 'period':

                        module_load_include('php', 'wrappers_custom', 'includes/taxonomy_term/PeriodTaxonomyTermWrapper');
                        // ampiana ity indray raha niveau
                        $period = new PeriodTaxonomyTermWrapper($tid);
                        
                        $form['taxonomy']['taompianaran'] = array(
                            '#type' => 'textfield',
                            '#title' => t('Année scolaire : '),
                            '#default_value' => $period->getTaompianarana()->name,
                        );
                        
                        $form['taxonomy']['start_date'] = array(
                            '#type' => 'textfield',
                            '#title' => t('Date debut de cette periode : '),
                            '#default_value' => date('d - M - Y', $period->getStartDate()),
                        );
                        
                        $form['taxonomy']['end_date'] = array(
                            '#type' => 'textfield',
                            '#title' => t('Date fin de cette periode : '),
                            '#default_value' => date('d - M - Y', $period->getEndDate()),
                        );

                        break;

                    default:
                        break;
                }


                $form['taxonomy']['description'] = array(
                    '#type' => 'textarea',
                    '#title' => t('Description : '),
                    '#default_value' => str_replace(array('<p>', '</p>'), array('', ''), $tag->getDescription()),
                );

                $form['taxonomy']['submit'] = array(
                    '#type' => 'submit',
                    '#value' => t('Enregistrer les modification'),
                );

                $form['#attached']['css'][] = array('data' => drupal_get_path('module', 'entity_entity') . '/tools/css_entity.css', 'type' => 'file');
            }
        } catch (Exception $e) {
            drupal_set_message(t('Taxonomy introvable'), 'error');
        }
    }
    return $form;
}

function _taxonomy_load_form_submit($form, &$form_state) {

    $tag = new WdTaxonomyTermWrapper($form_state['tid']);
    $tag->setName($form_state['values']['name']);
    $tag->setDescription($form_state['values']['description']);
    $tag->save();
}
