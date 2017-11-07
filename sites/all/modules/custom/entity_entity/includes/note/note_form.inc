<?php

module_load_include('php', 'wrappers_custom', 'includes/user/UserUserWrapper');
module_load_include('inc', 'entity_entity', 'includes/relation/classMatieres');
module_load_include('php', 'wrappers_custom', 'includes/taxonomy_term/ClasseTaxonomyTermWrapper');
module_load_include('php', 'wrappers_custom', 'includes/taxonomy_term/ClasseTaxonomyTermWrapper');

function fiche_note_form($form, &$form_state) {

    // ity no eo amin'ny voalohany apovoany
    $markup = t('<div class="entete_center"><H3>REPOBLIKAN\'I MADAGASIKARA</H3><div class="">');
    $markup.= variable_get('FANEVA_MASCAR');
    $markup.= t('</br>**************************</div></div>');

    // ity no eo amin'ny sisiny ankavia
    $markup.= t('<div class="entete_left">');
    $markup.= t('<H3>DIRECTION REGIONAL DES ENSEIGNEMENT </H3>');
    $markup.= variable_get('DREN');
    $markup.= t('<H3>CIRCONSCRIPTION SCOLAIRE </H3>');
    $markup.= variable_get('CISCO');
    $markup.= t('</div>');


    $markup.= t('<div class="entete_right"><H3>ANNEE SCOLAIRE : </H3>');
    $markup.= variable_get('CISCO');
    $markup.= t('</div>');

    $markup.= t('<div class="entete_name">BULLETIN DE NOTES</div>');

    $markup.= t('<div class="entete_title"><H1> FICHE DE NOTE </H1></div>');

    $form['note'] = array(
        '#type' => 'markup',
        '#markup' => $markup,
    );

    $form['note_2'] = array(
        '#type' => 'container',
        '#prefix' => '<div class="list_eleve" >',
        '#suffix' => '</div>',
    );

    $form['note_2']['nom_prenom'] = array(
        '#type' => 'markup',
        '#markup' => t("<b>Nom et prénom :</b>"),
        '#prefix' => '<div class="" >',
    );

    $form['note_2']['date_naiss'] = array(
        '#type' => 'markup',
        '#markup' => t("<b>Date de naissance :</b>"),
        '#prefix' => '</br>',
    );

    $form['note_2']['num_mat'] = array(
        '#type' => 'markup',
        '#markup' => t("<b>Matricule :</b>"),
        '#prefix' => '</br>',
        '#suffix' => '</div>',
    );

    $form['note_2']['sex'] = array(
        '#type' => 'markup',
        '#markup' => t("<b>Sexe :</b>"),
        '#prefix' => '<div class="entete_title" >',
    );

    $form['note_2']['class'] = array(
        '#type' => 'markup',
        '#markup' => t("<b>Classe :</b>"),
        '#prefix' => '</br>',
        '#suffix' => '</div>',
    );

    $form['note_2']['numero'] = array(
        '#type' => 'markup',
        '#markup' => t("<b>Numero :</b>"),
        '#prefix' => '<div class="entete_right" >',
    );

    $form['note_2']['effectif'] = array(
        '#type' => 'markup',
        '#markup' => t("<b>Effectif :</b>"),
        '#prefix' => '</br>',
        '#suffix' => '</div>',
    );

    $form['#attached']['css'][] = array('data' => drupal_get_path('module', 'entity_entity') . '/tools/css_entity.css', 'type' => 'file');

    if (isset($_GET['pdf']) && $_GET['pdf'] == 1) {
        drupal_add_css(drupal_get_path('module', 'entity_entity') . '/tools/css_to_pdf.css');
    }
    return $form;
}

function _note_set_matiere_class_form($form, &$form_state) {

    $form['note'] = array(
        '#type' => 'fieldset',
        '#prefix' => '<div class="eleve_main_view">',
        '#suffix' => '</div>',
    );

    $options = UserUserWrapper::getAllUsers();
    $form['note']['user'] = array(
        '#type' => 'select',
        '#title' => t("Prof"),
        '#options' => $options,
        '#required' => TRUE,
        '#attributes' => array('class' => array('sexe_select')),
    );

    $options = _get_taxonomy_term('classe');
    $form['note']['class'] = array(
        '#type' => 'select',
        '#title' => t("Classe"),
        '#options' => $options,
        '#required' => TRUE,
        '#attributes' => array('class' => array('sexe_select')),
    );

    $options = _get_taxonomy_term('matieres');
    $form['note']['matiere'] = array(
        '#type' => 'select',
        '#title' => t("Matière"),
        '#options' => $options,
        '#required' => TRUE,
        '#attributes' => array('class' => array('sexe_select')),
    );

    $form['note']['coeff'] = array(
        '#type' => 'textfield',
        '#title' => t("Coeff"),
        '#required' => TRUE,
    );

    $form['note']['submit'] = array(
        '#type' => 'submit',
        '#value' => t("Enregistrer"),
        '#required' => TRUE,
    );

    $conditions = array(
        array(
            'field_name' => 'taompianarana_tid',
            'operator' => '=',
            'value' => variable_get('TAOMPIANARANA'),
        ),
    );
    if (_selectFromClassMatieres($conditions) != NULL) {

        $rows = array();

        $result = _selectFromClassMatieres($conditions);
        while ($record = $result->fetchAssoc()) {

            $row = array();
            $class = new ClasseTaxonomyTermWrapper($record['classe_tid']);
            $matiere = new MatieresTaxonomyTermWrapper($record['matiere_tid']);
            $user = new UserUserWrapper($record['prof_uid']);

            $row[] = $class->getName();
            $row[] = $matiere->getName();
            $row[] = $user->getName() . ' ' . $user->getNom();
            $row[] = $record['coeff'];

            $rows[] = $row;
        }

        $header = array(t("Classe") , t("Matière") , t("Prof") , t("Coeff"));
        $output = theme('table', array('header' => $header, 'rows' => $rows));
        $form['table'] = array(
            '#type' => 'markup',
            '#markup' => $output,
            '#prefix' => '<div id="">',
            '#suffix' => '</div>'
        );
    }
    $form['#attached']['css'][] = array('data' => drupal_get_path('module', 'entity_entity') . '/tools/css_entity.css', 'type' => 'file');

    return $form;
}

function _note_set_matiere_class_form_submit($form, &$form_state) {

    try {


        $prof_uid = $form_state['values']['user'];
        $class = $form_state['values']['class'];
        $matiere = $form_state['values']['matiere'];
        $coeff = $form_state['values']['coeff'];

        $taompianarana_tid = variable_get('TAOMPIANARANA');

        $conditions = array(
            array(
                'field_name' => 'taompianarana_tid',
                'operator' => '=',
                'value' => $taompianarana_tid,
            ),
            array(
                'field_name' => 'classe_tid',
                'operator' => '=',
                'value' => $class,
            ),
            array(
                'field_name' => 'matiere_tid',
                'operator' => '=',
                'value' => $matiere,
            )
        );

        $find = FALSE;
        if (_selectFromClassMatieres($conditions) != NULL) {

            $result = _selectFromClassMatieres($conditions);
            while ($record = $result->fetchAssoc()) {

                $find = TRUE;
            }
        }

        if ($find) {
            $fieldAndValue = array(
                'prof_uid' => $prof_uid,
                'coeff' => $coeff,
            );
            _updateClassMatieres($fieldAndValue, $conditions);
            drupal_set_message(t("Modification reussi"));
        } else {
            $saved = _insertIntoClassMatieres($taompianarana_tid, $class, $matiere, $prof_uid, $coeff);

            if ($saved != NULL) {

                drupal_set_message(t("Enregistrement reussi"));
            } else {

                drupal_set_message(t("Enregistrement echoé"), 'error');
            }
        }
    } catch (Exception $ex) {

        drupal_set_message(t("Enregistrement echoé"), 'error');
    }
}

function _note_form_mode_calcul($form, &$form_state) {
    
    
    $form['note'] = array(
        '#type' => 'fieldset',
        '#prefix' => '<div class="eleve_main_view">',
        '#suffix' => '</div>',
    );
    
    $header  = array(t('Id') , t('Nom'));
    $rows    = array();
    $options = _get_taxonomy_term('type_de_note');
    
    foreach ($options as $key => $value) {
        
        if( ! in_array($key, array(variable_get('NOTE_SUR_20'),variable_get('NOTE_DEFINITIF')))){
            $rows[] = array($key, $value);
        }
    }
    
    $output = theme('table', array('header' => $header, 'rows' => $rows));
    $form['note']['table'] = array(
        '#type' => 'markup',
        '#markup' => $output,
        '#prefix' => '<div id="">',
        '#suffix' => '</div>'
    );
    
    $form['mode'] = array(
        '#type' => 'fieldset',
        '#prefix' => '<div class="view_left">',
        '#suffix' => '</div>',
    );
    
    $form['mode']['operetion'] = array(
        '#type' => 'textarea',
        '#title'=> t('Mode de calcule de la note /20 : '),
        '#default_value'=>variable_get('OPERATION_'. variable_get('PERIODE')),
    );
    
    $form['mode']['submit'] = array(
        '#type' => 'submit',
        '#value'=> t('Enregistrer'),
    );
    
    return $form;
}


function _note_form_mode_calcul_validate($form , &$form_state) {
    
    $operetion      = $form_state['values']['operetion'];
    $search         = array('(',')','*','+','-','/',' ');
    $replace        = array('' , '', '', '', '', '', '');
    $operetionClean = str_replace($search, $replace, $operetion);
    $operetionArray = explode("@", $operetionClean);
    $type_de_note   = _get_taxonomy_term('type_de_note');
    $type_note_array= array_keys($type_de_note);
    
    foreach ($operetionArray as $value) {
        
        if( $value != NULL && ! in_array($value, $type_note_array)){

            $arrayValue = explode("#", $value);
            $countValue = count($arrayValue);
            
            if($arrayValue[$countValue -1] != NULL && ! in_array($arrayValue[$countValue -1], $type_note_array)){
            
                form_set_error('operetion', t('Erreur de type d\'operation'));
            }
        }
    }
    
    foreach ($type_note_array as $type_note) {
        
        $operetion = str_replace($type_note.'@', 20, $operetion);
    }
    
    $total = 0;
    if($operetion != NULL){
        
        $operetion = str_replace('#', '', $operetion);
        eval('$total = '.$operetion. ';');
    }
    
    if($total != 20){
        
        form_set_error('operetion', t('Erreur de type d\'operation : votre operation ne donnee la note 20/20'));
    }
    
}


function _note_form_mode_calcul_submit($form , &$form_state) {
    
    if(variable_get('PERIODE') != NULL){
        $operetion      = $form_state['values']['operetion'];
        variable_set('OPERATION_'. variable_get('PERIODE'), $operetion);
    }else{
        drupal_set_message(t('Avant d\'enregistrer l\'operation il faut électionnée la periode courante'));
    }
}