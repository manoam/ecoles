<?php

module_load_include('php', 'wrappers_custom', 'includes/user/UserUserWrapper');
module_load_include('inc', 'entity_entity', 'includes/relation/classMatieres');
module_load_include('php', 'wrappers_custom', 'includes/taxonomy_term/PeriodTaxonomyTermWrapper');
module_load_include('php', 'wrappers_custom', 'includes/taxonomy_term/TypeDeNoteTaxonomyTermWrapper');
module_load_include('php', 'wrappers_custom', 'includes/taxonomy_term/ClasseTaxonomyTermWrapper');

function fiche_note_form($form, &$form_state, $eleve_id) {

    try {

        if ($eleve_id != NULL) {

            $eleve = new EleveEleveWrapper($eleve_id);

            // ity no eo amin'ny voalohany apovoany
            $markup = t('<div class="entete_center"><H3>REPOBLIKAN\'I MADAGASIKARA</H3><div class="">');
            $markup.= variable_get('FANEVA_MASCAR');
            $markup.= t('</br>**************************</div></div>');

            // ity no eo amin'ny sisiny ankavia
            $markup.= t('<div class="entete_left">');
            $markup.= t('<H3>DIRECTION REGIONAL DE L\' EDUCATION NATIONALE </H3>');
            $markup.= variable_get('DREN');
            $markup.= t('<H3>CIRCONSCRIPTION SCOLAIRE </H3>');
            $markup.= variable_get('CISCO') . '</br>';
            $markup.= variable_get('ECOLE') . '</br>';
            $markup.= 'Code : ' . variable_get('CODE_ETAB');
            $markup.= t('</div>');


            $markup.= t('<div class="entete_right"><H3>ANNEE SCOLAIRE : </H3>');
            $t      = new TaompianaranaTaxonomyTermWrapper(variable_get('TAOMPIANARANA'));
            $markup.= $t->getName();
            $markup.= t('</div>');

            $markup.= t('<div class="entete_name">BULLETIN DE NOTES</div>');

            $period = new PeriodTaxonomyTermWrapper(variable_get('PERIODE'));
            $markup.= t('<div class="entete_title"><H1> ' . $period->getName() . '</H1></div>');

            // manomboka eto ny note
            $header = array();
            $rows = array();
            $getHeader  = TRUE;
            $totalNote  = 0;
            $totalCoeff = 0;
            $moyenne    = 0;
            $classe_tid = 0;
            // alaina izany aloha eto oe firy em ity ankizy ity
            $find_info = _look_up_eleve_in_eleve_taompianarana($eleve_id);
            if ($find_info != NULL && isset($find_info['CLASS_TID'])) {

                $form['note'] = array(
                    '#type' => 'markup',
                    '#markup' => $markup,
                );

                $form['note_2'] = array(
                    '#type' => 'container',
                    '#prefix' => '<div class="list_eleve" >',
                    '#suffix' => '</div>',
                );

                $nom = $eleve->getNom() . ' ' . $eleve->getPrenom();
                $form['note_2']['nom_prenom'] = array(
                    '#type' => 'markup',
                    '#markup' => t("<b>Nom et prénom : ") . $nom,
                    '#prefix' => '<div class="" >',
                );

                $date = date('d - M - Y', $eleve->getDateNaiss());
                $form['note_2']['date_naiss'] = array(
                    '#type' => 'markup',
                    '#markup' => t("Date de naissance : ") . $date,
                    '#prefix' => '</br>',
                );

                $num_mat = $eleve->getNumMat();
                $form['note_2']['num_mat'] = array(
                    '#type' => 'markup',
                    '#markup' => t("Matricule : ") . $num_mat,
                    '#prefix' => '</br>',
                    '#suffix' => '</div>',
                );

                $form['note_2']['numero'] = array(
                    '#type' => 'markup',
                    '#markup' => t("Numero : " . $find_info['NUM_CLASS'] . "</b>"),
                    '#prefix' => '<div class="entete_right up" >',
                );

                $form['note_2']['class'] = array(
                    '#type' => 'markup',
                    '#markup' => t("Classe : ".$find_info['CLASS_NAME']),
                    '#prefix' => '</br>',
                    '#suffix' => '</div>',
                );

                $sex = $eleve->getSex()->name;
                $form['note_2']['sex'] = array(
                    '#type' => 'markup',
                    '#markup' => t("Sexe : ") . $sex,
                    '#prefix' => '<div class="entete_right up" >',
                );
                
                $classe_tid = $find_info['CLASS_TID'];
                // manao ny calcule eto sao dia nisy tsy vita ny ankizy sasany
                $input = array('ID' => $eleve_id, 'CLASS_TID' => $classe_tid);

                $moyenne = note_calcul_generate_bulletin($input,$totalNote,$totalCoeff);
                
                if ($getHeader) {

                    $header[] = array('data' => 'Matiére', 'class' => array('header-bulletin'));
                }
                // alina indray ny matiere ataon'ilay class
                $conditions = array(
                    array(
                        'field_name' => 'taompianarana_tid',
                        'value' => variable_get('TAOMPIANARANA'),
                        'operator' => '=',
                    ),
                    array(
                        'field_name' => 'classe_tid',
                        'value' => $classe_tid,
                        'operator' => '=',
                    )
                );

                $result = _selectFromClassMatieres($conditions);
                while ($record = $result->fetchAssoc()) {

                    $row = array();

                    $matiereTerm = new MatieresTaxonomyTermWrapper($record['matiere_tid']);

                    $row[] = array('data' => $matiereTerm->getName(), 'class' => array('bulletin-note'));
                    // alina indray avy eo ny note an'ilay ankizy par rapport amin'ilay matiere
//
//                    $type_de_note = _get_taxonomy_term('type_de_note');
//                    $note_general = array(variable_get('NOTE_SUR_20'), variable_get('NOTE_DEFINITIF'));
//
//                    foreach ($type_de_note as $type_note => $note_name) {
//
//                        if (in_array($type_note, $note_general)) {
//                            continue;
//                        }
//
//                        $note = note_form_get_note_in_matiere($classe_tid, $record['matiere_tid'], $type_note, $eleve_id);
//
//                        if ($note != NULL) {
//
//                            if ($getHeader) {
//
//                                $header[] = array('data' => $note_name, 'class' => array('header-bulletin'));
//                            }
//                            $row[] = array('data' => $note, 'class' => array('bulletin-note'));
//                        }
//                    }

                    // rehefa azo daholo ny type de note izay vao apetraka ilay note sur 20 
                    $noteTerm = new TypeDeNoteTaxonomyTermWrapper(variable_get('NOTE_SUR_20'));

                    $_note = note_form_get_note_in_matiere($classe_tid, $record['matiere_tid'], variable_get('NOTE_SUR_20'), $eleve_id);

                    if ($_note != NULL) {

                        if ($getHeader) {

                            $header[] = array('data' => $noteTerm->getName(), 'class' => array('header-bulletin'));
                        }
                        $row[] = array('data' => $_note, 'class' => array('bulletin-note'));
                    }

                    // appetraka avy eo ny coeff
                    if ($getHeader) {

                        $header[] = array('data' => 'Coeff', 'class' => array('header-bulletin'));
                    }

                    $row[] = array('data' => $record['coeff'], 'class' => array('bulletin-note'));

                    // izay vao ny note definitif
                    $noteTerm = new TypeDeNoteTaxonomyTermWrapper(variable_get('NOTE_DEFINITIF'));


                    $note = note_form_get_note_in_matiere($classe_tid, $record['matiere_tid'], variable_get('NOTE_DEFINITIF'), $eleve_id);

                    if ($note != NULL) {

                        if ($getHeader) {

                            $header[] = array('data' => $noteTerm->getName(), 'class' => array('header-bulletin'));
                        }
                        $row[] = array('data' => $note, 'class' => array('bulletin-note'));
                    }
                    
                    // asiana ilay oe tres bien sns
                    if ($getHeader) {

                        $header[] = array('data' => 'Appreciation', 'class' => array('header-bulletin'));
                        $header[] = array('data' => 'Signature', 'class' => array('header-bulletin'));
                    }
                    
                    $row[] = array('data' => _appreciation($_note), 'class' => array('bulletin-note appreciation'));
                    $row[] = array('data' => '', 'class' => array('bulletin-note'));

                    $rows[] = $row;
                    $getHeader = FALSE;
                }
                
                $rowCount = count($row);
                $row = array();
                
                for($i = 0; $i < $rowCount; $i++){
                    
                    if($i == $rowCount - 6){
                        
                        $row[] = array('data' => '', 'class' => array('bulletin-right'));
                    }elseif($i == $rowCount - 5){
                        
                        $row[] = array('data' => 'Total', 'class' => array('bulletin-note'));
                    }elseif($i == $rowCount - 4){
                        
                        $row[] = array('data' => $totalCoeff, 'class' => array('bulletin-note'));
                    }elseif($i == $rowCount - 3){
                        
                        $row[] = array('data' => $totalNote, 'class' => array('bulletin-note'));
                    }else{
                        
                        $row[] = array('data' => '', 'class' => array('bulletin-no-border'));
                    }
                }
                
                $rows[] = $row;
            }

            $markup = theme('table', array('header' => $header, 'rows' => $rows));
            $form['table'] = array(
                '#type' => 'markup',
                '#markup' => $markup,
            );
            
            
            $name = variable_get('TAOMPIANARANA').'_'.variable_get('PERIODE').'_'.$classe_tid;
            $rang = variable_get($name);
            
            $form['footer']['moyenne'] = array(
                '#type' => 'markup',
                '#markup' => 'MOYENNE : '. number_format($moyenne, 2, "," ," ").' / 20 ' . " </br>Rang : ".$rang[$eleve_id.'_'] . ' / ' . count($rang) . ' éleves',
                '#prefix' => '<div class = "moyen">',
                '#suffix' => '</div>',
            );
            
            $form['note_2']['effectif'] = array(
                '#type' => 'markup',
                '#markup' => t("Effectif : ".count($rang) . " </b>"),
                '#prefix' => '</br>',
                '#suffix' => '</div></div>',
            );

            $form['footer']['footer'] = array(
                '#type' => 'markup',
                '#markup' => t("Decision du conseil de classe : " . _appreciation($moyenne)),
                '#prefix' => '<div class="decision appreciation">',
                '#suffix' => '</div>',
            );
            
            $form['footer']['date'] = array(
                '#type' => 'markup',
                '#markup' => t("Ankadinondry le : " ),
                '#prefix' => '<div class="entete_center">',
                '#suffix' => '</div>',
            );
            
            $form['footer']['responsable'] = array(
                '#type' => 'markup',
                '#markup' => t("Le Proffesseur responsable" ),
                '#prefix' => '<div class="">',
                '#suffix' => '</div>',
            );
            
            $form['footer']['president'] = array(
                '#type' => 'markup',
                '#markup' => t("President du conseil" ),
                '#prefix' => '<div class="signature-right">',
                '#suffix' => '</div>',
            );
        }
        
    } catch (Exception $ex) {
        
    }

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

        $result = _selectFromClassMatieres($conditions,$orderBy = 'classe_tid');
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

        $header = array(t("Classe"), t("Matière"), t("Prof"), t("Coeff"));
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

    $header = array(t('Id'), t('Nom'));
    $rows = array();
    $options = _get_taxonomy_term('type_de_note');

    foreach ($options as $key => $value) {

        if (!in_array($key, array(variable_get('NOTE_SUR_20'), variable_get('NOTE_DEFINITIF')))) {
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
        '#title' => t('Mode de calcule de la note /20 dans cette periode: '),
        '#default_value' => variable_get('OPERATION_' . variable_get('PERIODE')),
    );

    $form['mode']['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Enregistrer'),
    );

    return $form;
}

function _note_form_mode_calcul_validate($form, &$form_state) {

    $operetion = $form_state['values']['operetion'];
    $search = array('(', ')', '*', '+', '-', '/', ' ');
    $replace = array('', '', '', '', '', '', '');
    $operetionClean = str_replace($search, $replace, $operetion);
    $operetionArray = explode("@", $operetionClean);
    $type_de_note = _get_taxonomy_term('type_de_note');
    $type_note_array = array_keys($type_de_note);

    foreach ($operetionArray as $value) {

        if ($value != NULL && !in_array($value, $type_note_array)) {

            $arrayValue = explode("#", $value);
            $countValue = count($arrayValue);

            if ($arrayValue[$countValue - 1] != NULL && !in_array($arrayValue[$countValue - 1], $type_note_array)) {

                form_set_error('operetion', t('Erreur de type d\'operation'));
            }
        }
    }

    foreach ($type_note_array as $type_note) {

        $operetion = str_replace($type_note . '@', 20, $operetion);
    }

    $total = 0;
    if ($operetion != NULL) {

        $operetion = str_replace('#', '', $operetion);
        eval('$total = ' . $operetion . ';');
    }

    if ($total != 20) {

        form_set_error('operetion', t('Erreur de type d\'operation : votre operation ne donnee la note 20/20'));
    }
}

function _note_form_mode_calcul_submit($form, &$form_state) {

    if (variable_get('PERIODE') != NULL) {
        $operetion = $form_state['values']['operetion'];
        variable_set('OPERATION_' . variable_get('PERIODE'), $operetion);
    } else {
        drupal_set_message(t('Avant d\'enregistrer l\'operation il faut électionnée la periode courante'));
    }
}

function note_form_get_note_in_matiere($classe_tid, $matiere_tid, $type_note, $eleve_tid) {

    $conditions = array(
        array(
            'field_name' => 'taompianarana_tid',
            'operator' => '=',
            'value' => variable_get('TAOMPIANARANA'),
        ),
        array(
            'field_name' => 'periode_tid',
            'operator' => '=',
            'value' => variable_get('PERIODE'),
        ),
        array(
            'field_name' => 'classe_tid',
            'operator' => '=',
            'value' => $classe_tid,
        ),
        array(
            'field_name' => 'matiere_tid',
            'operator' => '=',
            'value' => $matiere_tid,
        ),
        array(
            'field_name' => 'type_note_tid',
            'operator' => '=',
            'value' => $type_note,
        ),
        array(
            'field_name' => 'eleve_tid',
            'operator' => '=',
            'value' => $eleve_tid,
        ),
    );

    $result = _selectFromEleveNote($conditions);

    if ($result != NULL) {

        while ($record = $result->fetchAssoc()) {

            return $record['note'];
        }
    }

    return NULL;
}


function _appreciation($_note) {
    
    switch ($_note) {
        case $_note>=16:
            return 'Trés Bien';
        case $_note<16 && $_note>=14:
            return 'Bien';
        case $_note<14 && $_note>=12:
            return 'Assez Bien';
        case $_note<12 && $_note>=10:
            return 'Passable';
        case $_note<10 && $_note>=7:
            return 'Insuffisant';
        case $_note<7 && $_note>=5:
            return 'Faible';
        case $_note<5:
            return 'Médiocre';

        default:
            return '';
    }
}