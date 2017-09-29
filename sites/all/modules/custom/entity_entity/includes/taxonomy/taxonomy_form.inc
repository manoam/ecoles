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
                    '#attributes' => array('class' => array('eleve_main_view')),
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
                            '#title' => t('Niveau concernant : '),
                            '#options' => $option,
                            '#default_value' => $class->getNiveau()->tid,
                            '#attributes' => array('class' => array('sexe_select')),
                        );
                        
                        $form['taxonomy']['code'] = array(
                            '#type' => 'textfield',
                            '#title' => t('Code pour l\'import excel ou csv : '),
                            '#default_value' => $class->getCode(),
                        );
                        
                        if ($class->getUsed() == '0' || $class->getUsed() == 0) {
                            $form['taxonomy']['submit'] = array(
                                '#type' => 'submit',
                                '#value' => t('Enregistrer les modification'),
                                '#weight' => 200,
                            );
                        }
                        break;

                    case 'niveau':

                        // ampiana ity indray raha niveau
                        $niveau = new NiveauTaxonomyTermWrapper($tid);
                        $form['taxonomy']['code'] = array(
                            '#type' => 'textfield',
                            '#title' => t('Code pour l\'import excel ou csv : '),
                            '#default_value' => $niveau->getCode(),
                        );

                        if ($niveau->getUsed() == '0' || $niveau->getUsed() == 0) {
                            $form['taxonomy']['submit'] = array(
                                '#type' => 'submit',
                                '#value' => t('Enregistrer les modification'),
                                '#weight' => 200,
                            );
                        }

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

                        if ($taompianarana->getUsed() == '0' || $taompianarana->getUsed() == 0) {
                            $form['taxonomy']['submit'] = array(
                                '#type' => 'submit',
                                '#value' => t('Enregistrer les modification'),
                                '#weight' => 200,
                            );
                        }

                        break;

                    case 'period':

                        module_load_include('php', 'wrappers_custom', 'includes/taxonomy_term/PeriodTaxonomyTermWrapper');
                        
                        // ampiana ity indray raha niveau
                        $period = new PeriodTaxonomyTermWrapper($tid);

                        $options = _get_taxonomy_term('taompianarana');
                        $form['taxonomy']['taompianarana'] = array(
                            '#type' => 'select',
                            '#title' => t('Année scolaire : '),
                            '#options'=>$options,
                            '#default_value' => $period->getTaompianarana()->tid,
                            '#attributes' => array('class' => array('sexe_select')),
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

                        if ($period->getUsed() == '0' || $period->getUsed() == 0) {
                            $form['taxonomy']['submit'] = array(
                                '#type' => 'submit',
                                '#value' => t('Enregistrer les modification'),
                                '#weight' => 200,
                            );
                        }

                        break;

                    default:
                        break;
                }


                $form['taxonomy']['description'] = array(
                    '#type' => 'textarea',
                    '#title' => t('Description : '),
                    '#default_value' => str_replace(array('<p>', '</p>'), array('', ''), $tag->getDescription()),
                );

                $form['#attached']['css'][] = array('data' => drupal_get_path('module', 'entity_entity') . '/tools/css_entity.css', 'type' => 'file');
            }
        } catch (Exception $ex) {

            drupal_set_message(t('Taxonomy introvable'), 'error');
        }
    }
    return $form;
}

function _taxonomy_load_form_submit($form, &$form_state) {

    $tid = $form_state['tid'];
    $name = $form_state['values']['name'];
    $description = $form_state['values']['description'];

    $term = new WdTaxonomyTermWrapper($tid);
    $vocabulary = $term->getBundle();

    try {

        switch ($vocabulary) {

            case 'classe':

                $niveau = $form_state['values']['niveau'];

                $code = $form_state['values']['code'];
                
                $classe = new ClasseTaxonomyTermWrapper($tid);
                $classe->setName($name);
                $classe->setDescription($description);
                $classe->setNiveau($niveau);
                $classe->setCode($code);
                $classe->save();

                break;

            case 'taompianarana':

                $start_date = strtotime($form_state['values']['start_date']);
                $end_date = strtotime($form_state['values']['end_date']);

                $taompianarana = new TaompianaranaTaxonomyTermWrapper($tid);
                $taompianarana->setName($name);
                $taompianarana->setDescription($description);
                $taompianarana->setStartDate($start_date);
                $taompianarana->setEndDate($end_date);
                $taompianarana->save();

                break;

            case 'period':

                $taompianarana = $form_state['values']['taompianarana'];
                $start_date = strtotime($form_state['values']['start_date']);
                $end_date = strtotime($form_state['values']['end_date']);

                $period = new PeriodTaxonomyTermWrapper($tid);
                $period->setName($name);
                $period->setDescription($description);
                $period->setStartDate($start_date);
                $period->setEndDate($end_date);
                $period->setTaompianarana($taompianarana);
                $period->save();

                break;

            case 'niveau':

                $code = $form_state['values']['code'];

                $niveau = new NiveauTaxonomyTermWrapper($tid);
                $niveau->setName($name);
                $niveau->setDescription($description);
                $niveau->setCode($code);
                $niveau->save();

                break;

            default:
                break;
        }
        
        drupal_set_message(t('Enregistrement reussi'));
    } catch (Exception $ex) {

        drupal_set_message(t('Enregistrement echoué'), 'error');
    }
}

function _taxonomy_create_form($form, &$form_state, $vocabulary) {

    if ($vocabulary != NULL) {

        $form_state['vocabulary'] = $vocabulary;

        $vocabularyname = $vocabulary;
        
        if ($vocabulary == 'taompianarana') {
            $vocabularyname = t('Année scolaire');
        }

        $form['taxonomy'] = array(
            '#type' => 'fieldset',
            '#title' => t('Taxonomy : ' . $vocabularyname),
            '#attributes' => array('class' => array('eleve_main_view')),
        );

        $form['taxonomy']['name'] = array(
            '#type' => 'textfield',
            '#title' => t('Nom : '),
            '#required' => TRUE,
        );

        switch ($vocabulary) {

            case 'classe':

                // ampiana niveau ilay izy raha class no miseho
                $option = _get_taxonomy_term('niveau');
                $form['taxonomy']['niveau'] = array(
                    '#type' => 'select',
                    '#title' => t('Niveau concernant : '),
                    '#options' => $option,
                    '#required' => TRUE,
                    '#attributes' => array('class' => array('sexe_select')),
                );

                $form['taxonomy']['code'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Code pour l\'import excel ou csv : '),
                    '#required' => TRUE,
                );
                break;

            case 'taompianarana':

                // ampiana ity indray raha niveau
                $form['taxonomy']['start_date'] = array(
                    '#type' => 'date_popup',
                    '#title' => t('Date debut de l\'année scolaire'),
                    '#date_format' => 'd - M - Y',
                    '#date_label_position' => 'none',
                    '#required' => TRUE,
                    '#attributes' => array('class' => array('date_create')),
                );

                $form['taxonomy']['end_date'] = array(
                    '#type' => 'date_popup',
                    '#title' => t('Date fin de l\'année scolaire'),
                    '#date_format' => 'd - M - Y',
                    '#date_label_position' => 'none',
                    '#required' => TRUE,
                    '#attributes' => array('class' => array('date_create')),
                );
                break;

            case 'period':

                $option = _get_taxonomy_term('taompianarana');
                $form['taxonomy']['taompianarana'] = array(
                    '#type' => 'select',
                    '#title' => t('Année scolaire : '),
                    '#options' => $option,
                    '#required' => TRUE,
                    '#attributes' => array('class' => array('sexe_select')),
                );

                $form['taxonomy']['start_date'] = array(
                    '#type' => 'date_popup',
                    '#title' => t('Date fin de periode'),
                    '#date_format' => 'd - M - Y',
                    '#date_label_position' => 'none',
                    '#required' => TRUE,
                    '#attributes' => array('class' => array('date_create')),
                );

                $form['taxonomy']['end_date'] = array(
                    '#type' => 'date_popup',
                    '#title' => t('Date fin de periode'),
                    '#date_format' => 'd - M - Y',
                    '#date_label_position' => 'none',
                    '#required' => TRUE,
                    '#attributes' => array('class' => array('date_create')),
                );
                break;

            case 'niveau':

                $form['taxonomy']['code'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Code utilisant pour l\'import excel'),
                    '#required' => TRUE,
                );
                break;

            default:
                break;
        }

        $form['taxonomy']['description'] = array(
            '#type' => 'textarea',
            '#title' => t('Description : '),
        );

        $form['taxonomy']['submit'] = array(
            '#type' => 'submit',
            '#value' => t('Enregistrer'),
        );

        $form['#attached']['css'][] = array('data' => drupal_get_path('module', 'entity_entity') . '/tools/css_entity.css', 'type' => 'file');
    }
    return $form;
}

function _taxonomy_create_form_submit($form, &$form_state) {

    $vocabulary = $form_state['vocabulary'];
    $name = $form_state['values']['name'];
    $description = $form_state['values']['description'];
    $saved = NULL;

    switch ($vocabulary) {

        case 'classe':

            $code = $form_state['values']['code'];
            $niveau = $form_state['values']['niveau'];
            $saved = ClasseTaxonomyTermWrapper::add($name, $niveau,$code, $description);

            break;

        case 'taompianarana':

            $start_date = strtotime($form_state['values']['start_date']);
            $end_date = strtotime($form_state['values']['end_date']);
            $saved = TaompianaranaTaxonomyTermWrapper::add($name, $start_date, $end_date, $description);

            break;

        case 'period':

            $taompianarana = $form_state['values']['taompianarana'];
            $start_date = strtotime($form_state['values']['start_date']);
            $end_date = strtotime($form_state['values']['end_date']);
            $saved = PeriodTaxonomyTermWrapper::add($name, $taompianarana, $start_date, $end_date, $description);

            break;

        case 'niveau':

            $code = $form_state['values']['code'];
            $saved = NiveauTaxonomyTermWrapper::add($name, $code, $description);

            break;

        default:
            break;
    }

    if ($saved != NULL) {
        drupal_set_message(t('Enregistrement reussi'));
    } else {
        drupal_set_message(t('Enregistrement echoué'), 'error');
    }
}
