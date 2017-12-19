<?php

module_load_include('php', 'wrappers_custom', 'includes/eleve/EleveEleveWrapper');
module_load_include('php', 'wrappers_custom', 'includes/taxonomy_term/ClasseTaxonomyTermWrapper');
module_load_include('php', 'wrappers_custom', 'includes/taxonomy_term/NiveauTaxonomyTermWrapper');
module_load_include('inc', 'entity_entity', 'includes/relation/eleveTaompianarana');
module_load_include('inc', 'entity_entity', 'includes/eleve/eleve.list');
module_load_include('inc', 'entity_entity', 'tools/upload_photo');

/**
 * ity no solon'ilay form rehefa mijery ny eleve
 * @param type $form
 * @param type $form_state
 * @param type $eleve_id
 * @return array
 */
function _ecoles_eleve_form($form, &$form_state, $eleve_id) {

    if ($eleve_id != NULL && $eleve_id != 0) {

        try {

            $eleve = new EleveEleveWrapper($eleve_id);
            if ($eleve != NULL) {

                $form['eleve'] = array(
                    '#type' => 'fieldset',
                    '#title' => t('Information sur l\'eleve'),
                    '#prefix' => '<div class="eleve_main_view">',
                    '#suffix' => '</div>',
                );
                $form['eleve']['photo'] = array(
                    '#type' => 'markup',
                    '#markup' => $eleve->getProfileImage(),
                    '#prefix' => '<div class="eleve_image">',
                    '#suffix' => '</div>',
                );
                $form['eleve']['num_mat'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Num Matricule'),
                    '#value' => $eleve->getTitle(),
                    '#size' => '18',
                    '#attributes' => array('readonly' => 'readonly'),
                    '#prefix' => '<div class="right_in_fieldset">',
                        // any amin'ny sexe ity no mifarana
                );
                $form['eleve']['Nom'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Nom :'),
                    '#size' => '18',
                    '#value' => $eleve->getNom(),
                    '#attributes' => array('readonly' => 'readonly'),
                );
                $form['eleve']['prenom'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Prenom :'),
                    '#size' => '18',
                    '#value' => $eleve->getPrenom(),
                    '#attributes' => array('readonly' => 'readonly'),
                );

                $form['eleve']['sexe'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Sexe'),
                    '#size' => '18',
                    '#value' => $eleve->getSex() != NULL ? $eleve->getSex()->name : '',
                    '#attributes' => array('readonly' => 'readonly'),
                    '#suffix' => '</div>',
                );
                $form['eleve']['date'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Date de naissance'),
                    '#size' => '18',
                    '#value' => date('d - M - Y', $eleve->getDateNaiss()),
                    '#attributes' => array('readonly' => 'readonly'),
                );
                $form['eleve']['lieu'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Lieu'),
                    '#size' => '18',
                    '#value' => $eleve->getLieu(),
                    '#attributes' => array('readonly' => 'readonly'),
                );
                $form['eleve']['adress'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Adress'),
                    '#size' => '18',
                    '#value' => $eleve->getAdress(),
                    '#attributes' => array('readonly' => 'readonly'),
                );
                $form['eleve']['tel'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Num tel'),
                    '#size' => '18',
                    '#value' => $eleve->getTel(),
                    '#attributes' => array('readonly' => 'readonly'),
                );

                // ----------- ity no ampidirana ny ray aman-dreny -------------
                $form['eleve_parent'] = array(
                    '#type' => 'fieldset',
                    '#title' => t('Information Parent'),
                    '#prefix' => '<div class="view_left">',
                    '#suffix' => '</div>',
                );

                $form['eleve_parent']['nom_pere'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Nom du père :'),
                    '#size' => '18',
                    '#value' => $eleve->getNomPere(),
                    '#attributes' => array('readonly' => 'readonly'),
                );

                $form['eleve_parent']['function_pere'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Fonction du père :'),
                    '#size' => '18',
                    '#value' => $eleve->getProfessionPere(),
                    '#attributes' => array('readonly' => 'readonly'),
                );

                $form['eleve_parent']['nom_mere'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Nom de la mère :'),
                    '#size' => '18',
                    '#value' => $eleve->getNomMere(),
                    '#attributes' => array('readonly' => 'readonly'),
                );

                $form['eleve_parent']['function_mere'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Fonction de la mère :'),
                    '#size' => '18',
                    '#value' => $eleve->getProfessionMere(),
                    '#attributes' => array('readonly' => 'readonly'),
                );

                $form['eleve_parent']['parent_adress'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Adresse de parent :'),
                    '#size' => '18',
                    '#value' => $eleve->getParentAdress(),
                    '#attributes' => array('readonly' => 'readonly'),
                );

                $form['eleve_parent']['nom_tuteur'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Nom du Tuteur :'),
                    '#size' => '18',
                    '#value' => $eleve->getNomTuteur(),
                    '#attributes' => array('readonly' => 'readonly'),
                );

                $form['eleve_parent']['function_tuteur'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Fonction du Tuteur :'),
                    '#size' => '18',
                    '#value' => $eleve->getProfessionTuteur(),
                    '#attributes' => array('readonly' => 'readonly'),);

                $form['eleve_parent']['num_tel_tuteur'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Numero Telephone du Tuteur :'),
                    '#size' => '18',
                    '#value' => $eleve->getNumTelTuteur(),
                    '#attributes' => array('readonly' => 'readonly'),);

                $form['eleve_parent']['adrres_tuteur'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Adresse du Tuteur :'),
                    '#size' => '18',
                    '#value' => $eleve->getAdressTuteur(),
                    '#attributes' => array('readonly' => 'readonly'),);

                // ----------- ity no ampidirana ny ray aman-dreny -------------
                $form['eleve_class'] = array(
                    '#type' => 'fieldset',
                    '#title' => t('Classe'),
                    '#prefix' => '<div class="list_eleve">',
                    '#suffix' => '</div>',
                );

                $find_info = _look_up_eleve_in_eleve_taompianarana($eleve->getId());

                if ($find_info != NULL) {

                    $markup = '<div class="message_inscrit_yes">';
                    $markup .= t("<p>Cet élève est inscrit dans notre écoles  pour cette année scolaire. ");
                    $markup .= t("Il est déjà dans le niveau " . $find_info['NIVEAU_NAME'] . ".");

                    if (isset($find_info['CLASS_NAME'])) {
                        $markup .= t(" Et dans la class de " . $find_info['CLASS_NAME'] . "</p>");
                    } else {
                        $markup .= t('</p><p class="message_inscrit_no"> Mais il n\'est pas encore dans une classe.</p>');
                    }
                    $markup .= '</div>';

                    $form['eleve_class']['eleve_niveau'] = array(
                        '#type' => 'markup',
                        '#markup' => $markup,
                    );

                    $form['eleve_class']['tetid'] = array(
                        '#type' => 'hidden',
                        '#value' => $find_info['ID'],
                    );

                    if (!isset($find_info['CLASS_NAME'])) {

                        $options = ClasseTaxonomyTermWrapper::getClassByNiveau($find_info['NIVEAU_TID']);

                        $form['eleve_class']['eleve_class'] = array(
                            '#type' => 'select',
                            '#title' => t('Classe'),
                            '#options' => $options,
                            '#required' => TRUE,
                                //'#attributes' => array('class' => array('sexe_select')),
                        );
                        $form['eleve_class']['submit'] = array(
                            '#type' => 'submit',
                            '#value' => t('Enregistrer dans cette class'),
                        );
                    }
                } else {

                    $markup = '<div class="message_inscrit_no">';
                    $markup .= t("<p>Cet élève n'est pas encore inscrit dans notre écoles pour cette année scolaire</p>");
                    $markup .= '<a href=' . base_path() . 'ecoles/eleve/re-inscription?eleve_id=' . $eleve->getId() . '>' . t('Inscrire') . '</a>';
                    $markup .= '</div>';

                    $form['eleve_class']['eleve_class'] = array(
                        '#type' => 'markup',
                        '#markup' => $markup,
                    );
                }
                $form['#attached']['css'][] = array('data' => drupal_get_path('module', 'entity_entity') . '/tools/css_entity.css', 'type' => 'file');
            }
        } catch (Exception $e) {
            $e->getMessage();
        }
    }
    return $form;
}

function _ecoles_eleve_form_submit($form, &$form_state) {

    $table_id = $form_state['values']['tetid'];
    $eleve_class = $form_state['values']['eleve_class'];

    $fieldAndValue = array(
        'class_tid' => $eleve_class,
    );
    $conditions = array(
        array(
            'field_name' => 'id',
            'value' => $table_id,
            'operator' => '=',
        )
    );

    if (_updateEleveTaompianarana($fieldAndValue, $conditions) != NULL) {
        drupal_set_message(t('Enregistrement reussi'));
    } else {
        drupal_set_message(t('Enregistrement echoé'), 'error');
    }
}

/**
 * 
 * creation miaraka amin'ny inscription ity
 * 
 * @param type $form
 * @param type $form_state
 * @return string
 */
function _ecoles_create_eleve_form($form, &$form_state) {

    $form['eleve'] = array(
        '#type' => 'fieldset',
        '#title' => t('Information sur l\'eleve'),
        '#prefix' => '<div class="eleve_main_view">',
        '#suffix' => '</div>',
    );
    $form['eleve']['num_mat'] = array(
        '#type' => 'textfield',
        '#title' => t('Num Matricule'),
        '#size' => '18',
        '#required' => TRUE,
        '#attributes' => array(
            'placeholder' => array('Laharana'),
            'onKeypress' => _entity_entity_javascript_verification_int(),
        )
    );

    $form['#attributes'] = array(
        'enctype' => 'multipart/form-data'
    );

    $form['eleve']['photo'] = array(
        '#title' => t('Photo'),
        '#type' => 'file',
    );

    $form['eleve']['Nom'] = array(
        '#type' => 'textfield',
        '#title' => t('Nom :'),
        '#size' => '18',
        '#required' => TRUE,
        '#attributes' => array(
            'placeholder' => array('Anarana'),
        ),
    );
    $form['eleve']['prenom'] = array(
        '#type' => 'textfield',
        '#title' => t('Prenom :'),
        '#size' => '18',
        '#attributes' => array('placeholder' => array('Fanampin\'anarana')),
    );

    $options = _get_taxonomy_term('sexe');
    $form['eleve']['sexe'] = array(
        '#type' => 'select',
        '#title' => t('Sexe'),
        '#options' => $options,
        '#required' => TRUE,
        '#attributes' => array('class' => array('sexe_select')),
    );
    $form['eleve']['date'] = array(
        '#type' => 'date_popup',
        '#title' => t('Date de naissance'),
        '#size' => '18',
        '#date_format' => 'd - M - Y',
        '#date_year_range' => '-30:-10',
        '#date_month_range' => '-:-',
        '#date_label_position' => 'none',
        '#required' => TRUE,
        '#attributes' => array('placeholder' => array('Daty nahaterahana'), 'class' => array('date_create')),
    );
    $form['eleve']['lieu'] = array(
        '#type' => 'textfield',
        '#title' => t('Lieu'),
        '#size' => '18',
        '#required' => TRUE,
        '#attributes' => array('placeholder' => array('Toerana nahaterahana')),
    );
    $form['eleve']['adress'] = array(
        '#type' => 'textfield',
        '#title' => t('Adress'),
        '#size' => '18',
        '#required' => TRUE,
        '#attributes' => array('placeholder' => array('Toerana ipetrahana')),
    );
    $form['eleve']['tel'] = array(
        '#type' => 'textfield',
        '#title' => t('Num tel'),
        '#size' => '18',
        '#attributes' => array('placeholder' => array('+26100000000')),
    );

    // ----------- ity no ampidirana ny ray aman-dreny -------------
    $form['eleve_parent'] = array(
        '#type' => 'fieldset',
        '#title' => t('Information Parent'),
        '#prefix' => '<div class="view_left">',
        '#suffix' => '</div>',
    );

    $form['eleve_parent']['nom_pere'] = array(
        '#type' => 'textfield',
        '#title' => t('Nom du père :'),
        '#size' => '18',
        '#attributes' => array(
            'placeholder' => array('Anaranan\'ny ray'),
        ),
    );

    $form['eleve_parent']['function_pere'] = array(
        '#type' => 'textfield',
        '#title' => t('Fonction du père :'),
        '#size' => '18',
        '#attributes' => array('placeholder' => array('asan\'ny ray')),
    );

    $form['eleve_parent']['nom_mere'] = array(
        '#type' => 'textfield',
        '#title' => t('Nom de la mère :'),
        '#size' => '18',
        '#attributes' => array(
            'placeholder' => array('Anaranan\'ny reny'),
        ),
    );

    $form['eleve_parent']['function_mere'] = array(
        '#type' => 'textfield',
        '#title' => t('Fonction de la mère :'),
        '#size' => '18',
        '#attributes' => array('placeholder' => array('Asan\'ny reny')),
    );

    $form['eleve_parent']['parent_adress'] = array(
        '#type' => 'textfield',
        '#title' => t('Adresse de parent :'),
        '#size' => '18',
        '#attributes' => array('placeholder' => array('Lot :')),
    );

    $form['eleve_parent']['nom_tuteur'] = array(
        '#type' => 'textfield',
        '#title' => t('Nom du Tuteur :'),
        '#size' => '18',
        '#attributes' => array(
            'placeholder' => array('Anaranan\'ny mpiantoka'),
        ),
    );

    $form['eleve_parent']['function_tuteur'] = array(
        '#type' => 'textfield',
        '#title' => t('Fonction du Tuteur :'),
        '#size' => '18',
        '#attributes' => array('placeholder' => array('Asan\'ny mpiantoka')),
    );

    $form['eleve_parent']['num_tel_tuteur'] = array(
        '#type' => 'textfield',
        '#title' => t('Numero Telephone du Tuteur :'),
        '#size' => '18',
        '#attributes' => array('placeholder' => array('+261000000000')),
    );

    $form['eleve_parent']['adrres_tuteur'] = array(
        '#type' => 'textfield',
        '#title' => t('Adresse du Tuteur :'),
        '#size' => '18',
        '#attributes' => array('placeholder' => array('Adiresin\'ny mpiantoka')),
    );

    // ----------- ity no ampidirana ny Niveau -------------
    $form['eleve_class'] = array(
        '#type' => 'fieldset',
        '#title' => t('Classe'),
        '#prefix' => '<div class="list_eleve">',
        '#suffix' => '</div>',
    );

    $options_niveau = _get_taxonomy_term('niveau');

    $form['eleve_class']['eleve_niveau'] = array(
        '#type' => 'select',
        '#title' => t('Niveau'),
        '#options' => $options_niveau,
        '#required' => TRUE,
    );


    $options = _get_taxonomy_term('redoublement');

    $form['eleve_class']['eleve_redouble'] = array(
        '#type' => 'select',
        '#title' => t('Redoublement :'),
        '#options' => $options
    );

    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Enregistrer'),
        '#prefix' => '<div class="list_eleve">',
        '#suffix' => '</div>',
    );

    // info asiana ilay sary
    $form_state['destination_photo'] = FILE_PHOTO;
    $form_state['form_name'] = 'photo';

    $form['#attached']['css'][] = array('data' => drupal_get_path('module', 'entity_entity') . '/tools/css_entity.css', 'type' => 'file');
    return $form;
}

function _ecoles_create_eleve_form_submit($form, &$form_state) {

    $db_transaction = db_transaction();

    try {

        $values = $form_state['values'];

        $num_mat = $values['num_mat'];
        $nom = $values['Nom'];
        $prenom = $values['prenom'];
        $sexe = $values['sexe'];
        $date = $values['date'];
        $lieu = $values['lieu'];
        $adress = $values['adress'];
        $nom_pere = $values['nom_pere'];
        $function_pere = $values['function_pere'];
        $nom_mere = $values['nom_mere'];
        $function_mere = $values['function_mere'];
        $parent_adress = $values['parent_adress'];
        $nom_tuteur = $values['nom_tuteur'];
        $function_tuteur = $values['function_tuteur'];
        $num_tel_tuteur = $values['num_tel_tuteur'];
        $adrres_tuteur = $values['adrres_tuteur'];
        $tel = $values['tel'];
        $niveau_tid = $values['eleve_niveau'];
        $eleve_redouble = $values['eleve_redouble'] != NULL ? $values['eleve_redouble'] : NULL;
        $error_message = array();

        $eleve_id = EleveEleveWrapper::addEleve($num_mat, $nom, $prenom, $sexe, $date, $lieu, $adress, $tel, $nom_pere, $function_pere, $nom_mere, $function_mere, $parent_adress, $nom_tuteur, $function_tuteur, $num_tel_tuteur, $adrres_tuteur, $error_message);

        if ($eleve_id != NULL) {

            $eleve = new EleveEleveWrapper($eleve_id);
            $source_file = _upload_photo($form, $form_state);

            // raha nisy ilay sary dia mditra eto
            if ($source_file != NULL) {
                $filePath = variable_get('PUBLIC_FILE', 'public://') . FILE_PHOTO;
                $photo_name = $eleve->getId() . '_' . $eleve->getNumMat();
                $dir = file_stream_wrapper_get_instance_by_uri($filePath)->realpath();
                $destination_file = $dir . '/' . $photo_name;
                $ext = NULL;
                // miditra eto vao hazo ilay extension an'ilay sary
                _upload_photo_compress_and_copy_image($source_file, $destination_file, $ext);

                if ($ext != NULL) {
                    $eleve->setPhoto(array(PUBLIC_FILE . '/' . FILE_PHOTO . '/' . $photo_name . '.' . $ext));
                    $eleve->save();
                }
            }

            $taompianarana_tid = variable_get('TAOMPIANARANA');

            $saved = _insertIntoEleveTaompianarana($eleve_id, $taompianarana_tid, $niveau_tid, $eleve_redouble);

            if ($saved != NULL) {
                drupal_set_message(t('Enregistrement reussi'));
            } else {
                $db_transaction->rollback();
                drupal_set_message(t('Enregistrement echoé'), 'error');
            }
        } else {

            drupal_set_message(t('Enregistrement echoé'), 'error');

            foreach ($error_message as $value) {
                drupal_set_message($value, 'error');
            }
        }
    } catch (Exception $ex) {
        $db_transaction->rollback();
    }
}

/**
 * 
 * Ity indray raha hanao re-inscription
 * @param type $form
 * @param type $form_state
 * @return string
 */
function _ecoles_reinscription_eleve_form($form, &$form_state) {

    $eleve = NULL;

    if (isset($_GET['eleve_id']) && $_GET['eleve_id'] != NULL) {
        $eleve = EleveEleveWrapper::getById($_GET['eleve_id']);
    }

    if (isset($form_state['values']['num_mat']) && $form_state['values']['num_mat'] != NULL) {
        $eleve = EleveEleveWrapper::getByNumMat($form_state['values']['num_mat']);
    }


    $form['eleve'] = array(
        '#type' => 'fieldset',
        '#title' => t('Information sur l\'eleve'),
        '#prefix' => '<div id="eleve_main_view" class="eleve_main_view">',
        '#suffix' => '</div>',
    );

    $form['eleve']['num_mat'] = array(
        '#type' => 'textfield',
        '#title' => t('Num Matricule'),
        '#autocomplete_path' => 'ecoles/autocomplete/eleve/by-num-mat',
        '#size' => '18',
        '#required' => TRUE,
        '#default_value' => $eleve != NULL ? $eleve->getNumMat() : '',
        '#attributes' => array(
            'placeholder' => array('Laharana'),
            'onKeypress' => _entity_entity_javascript_verification_int(),
        ),
        '#ajax' => array(
            'callback' => '_ajax_get_eleve_by_num_callback',
            'wrapper' => 'eleve',
        )
    );

    $form['eleve']['Nom'] = array(
        '#type' => 'textfield',
        '#title' => t('Nom :'),
        '#size' => '18',
        '#value' => $eleve != NULL ? $eleve->getNom() : '',
        '#attributes' => array('readonly' => 'readonly'),
    );
    $form['eleve']['prenom'] = array(
        '#type' => 'textfield',
        '#title' => t('Prenom :'),
        '#size' => '18',
        '#value' => $eleve != NULL ? $eleve->getPrenom() : '',
        '#attributes' => array('readonly' => 'readonly'),
    );
    $form['eleve']['sexe'] = array(
        '#type' => 'textfield',
        '#title' => t('Sexe :'),
        '#size' => '18',
        '#value' => $eleve != NULL ? ($eleve->getSex() != NULL ? $eleve->getSex()->name : 'non definie') : '',
        '#attributes' => array('readonly' => 'readonly'),
    );
    $form['eleve']['date'] = array(
        '#type' => 'textfield',
        '#title' => t('Date de naissance'),
        '#size' => '18',
        '#value' => $eleve != NULL ? date('d - M - Y', $eleve->getDateNaiss()) : '',
        '#attributes' => array('readonly' => 'readonly'),
    );
    $form['eleve']['lieu'] = array(
        '#type' => 'textfield',
        '#title' => t('Lieu'),
        '#size' => '18',
        '#value' => $eleve != NULL ? $eleve->getLieu() : '',
        '#attributes' => array('readonly' => 'readonly'),
    );
    $form['eleve']['adress'] = array(
        '#type' => 'textfield',
        '#title' => t('Adress'),
        '#size' => '18',
        '#value' => $eleve != NULL ? $eleve->getAdress() : '',
        '#attributes' => array('readonly' => 'readonly'),
    );
    $form['eleve']['tel'] = array(
        '#type' => 'textfield',
        '#title' => t('Num tel'),
        '#size' => '18',
        '#value' => $eleve != NULL ? $eleve->getTel() : '',
        '#attributes' => array('readonly' => 'readonly'),
    );

    // ----------- ity no ampidirana ny ray aman-dreny -------------
    $form['eleve_parent'] = array(
        '#type' => 'fieldset',
        '#title' => t('Information Parent'),
        '#prefix' => '<div class="view_left" id="view_left">',
        '#suffix' => '</div>',
    );

    $form['eleve_parent']['nom_pere'] = array(
        '#type' => 'textfield',
        '#title' => t('Nom du père :'),
        '#size' => '18',
        '#value' => $eleve != NULL ? $eleve->getNomPere() : '',
        '#attributes' => array('readonly' => 'readonly'),
    );

    $form['eleve_parent']['function_pere'] = array(
        '#type' => 'textfield',
        '#title' => t('Fonction du père :'),
        '#size' => '18',
        '#value' => $eleve != NULL ? $eleve->getProfessionPere() : '',
        '#attributes' => array('readonly' => 'readonly'),
    );

    $form['eleve_parent']['nom_mere'] = array(
        '#type' => 'textfield',
        '#title' => t('Nom de la mère :'),
        '#size' => '18',
        '#value' => $eleve != NULL ? $eleve->getNomMere() : '',
        '#attributes' => array('readonly' => 'readonly'),
    );

    $form['eleve_parent']['function_mere'] = array(
        '#type' => 'textfield',
        '#title' => t('Fonction de la mère :'),
        '#size' => '18',
        '#value' => $eleve != NULL ? $eleve->getProfessionMere() : '',
        '#attributes' => array('readonly' => 'readonly'),
    );

    $form['eleve_parent']['parent_adress'] = array(
        '#type' => 'textfield',
        '#title' => t('Adresse de parent :'),
        '#size' => '18',
        '#value' => $eleve != NULL ? $eleve->getParentAdress() : '',
        '#attributes' => array('readonly' => 'readonly'),
    );

    $form['eleve_parent']['nom_tuteur'] = array(
        '#type' => 'textfield',
        '#title' => t('Nom du Tuteur :'),
        '#size' => '18',
        '#value' => $eleve != NULL ? $eleve->getNomTuteur() : '',
        '#attributes' => array('readonly' => 'readonly'),
    );

    $form['eleve_parent']['function_tuteur'] = array(
        '#type' => 'textfield',
        '#title' => t('Fonction du Tuteur :'),
        '#size' => '18',
        '#value' => $eleve != NULL ? $eleve->getProfessionTuteur() : '',
        '#attributes' => array('readonly' => 'readonly'),
    );

    $form['eleve_parent']['num_tel_tuteur'] = array(
        '#type' => 'textfield',
        '#title' => t('Numero Telephone du Tuteur :'),
        '#size' => '18',
        '#value' => $eleve != NULL ? $eleve->getNumTelTuteur() : '',
        '#attributes' => array('readonly' => 'readonly'),
    );

    $form['eleve_parent']['adrres_tuteur'] = array(
        '#type' => 'textfield',
        '#title' => t('Adresse du Tuteur :'),
        '#size' => '18',
        '#value' => $eleve != NULL ? $eleve->getAdressTuteur() : '',
        '#attributes' => array('readonly' => 'readonly'),
    );


    // ----------- ity no ampidirana ny ray aman-dreny -------------
    $form['eleve_class'] = array(
        '#type' => 'fieldset',
        '#title' => t('Classe'),
        '#prefix' => '<div class="list_eleve" id="eleve_class">',
        '#suffix' => '</div>',
    );

    // jerena ilay eleve raha efa voasoratra anarana

    $find_info = array();

    if ($eleve != NULL) {

        $find_info = _look_up_eleve_in_eleve_taompianarana($eleve->getId());
    }

    if (count($find_info) > 0) {

        $markup = '<div class="message_inscrit_yes">';
        $markup .= t("<p>Cet élève est desormais inscrit dans notre écoles pour cette année scolaire</p>");
        $markup .= t("<p>Il est déjà dans le niveau " . $find_info['NIVEAU_NAME'] . "</p>");
        if (isset($find_info['CLASS_NAME'])) {
            $markup .= t("<p> Et dans la class de " . $find_info['CLASS_NAME'] . "</p>");
        } else {
            $markup .= t('<p class="message_inscrit_no"> Mais il n\'est pas encore dans une classe.</p>');
        }
        $markup .= '</div>';

        $form['eleve_class']['eleve_class'] = array(
            '#type' => 'markup',
            '#markup' => $markup,
        );

        $form['submit'] = array(
            '#type' => 'hidden',
            '#prefix' => '<div class="list_eleve" id="submit">',
            '#suffix' => '</div>',
        );
    } else {

        $options = _get_taxonomy_term('niveau');

        $form['eleve_class']['eleve_niveau'] = array(
            '#type' => 'select',
            '#title' => t('Niveau :'),
            '#required' => TRUE,
            '#options' => $options
        );

        $options = _get_taxonomy_term('redoublement');

        $form['eleve_class']['eleve_redouble'] = array(
            '#type' => 'select',
            '#title' => t('Redoublement :'),
            '#required' => TRUE,
            '#options' => $options
        );

        $form['submit'] = array(
            '#type' => 'submit',
            '#value' => t('Enregistrer'),
            '#prefix' => '<div class="list_eleve" id="submit">',
            '#suffix' => '</div>',
        );
    }
    $form['#attached']['css'][] = array('data' => drupal_get_path('module', 'entity_entity') . '/tools/css_entity.css', 'type' => 'file');
    return $form;
}

/**
 * 
 * @param type $form
 * @param type $form_state
 * @return type
 */
function _ajax_get_eleve_by_num_callback($form, &$form_state) {
    $commands = array();

    $eleve_main_view = $form['eleve'];
    $view_left = $form['eleve_parent'];
    $eleve_class = $form['eleve_class'];
    $submit = $form['submit'];

    $commands[] = ajax_command_replace('#eleve_main_view', drupal_render($eleve_main_view));
    $commands[] = ajax_command_replace('#view_left', drupal_render($view_left));
    $commands[] = ajax_command_replace('#eleve_class', drupal_render($eleve_class));
    $commands[] = ajax_command_replace('#submit', drupal_render($submit));
    return array('#type' => 'ajax', '#commands' => $commands);
}

function _ecoles_reinscription_eleve_form_submit($form, &$form_state) {

    $eleve = NULL;
    if (isset($form_state['values']['num_mat']) && $form_state['values']['num_mat'] != NULL) {

        $eleve = EleveEleveWrapper::getByNumMat($form_state['values']['num_mat']);
        $niveau_tid = $form_state['values']['eleve_niveau'];
        $eleve_redouble = $form_state['values']['eleve_redouble'];
        $taompianarana_tid = variable_get('TAOMPIANARANA');

        if ($eleve != NULL) {

            $saved = _insertIntoEleveTaompianarana($eleve->getId(), $taompianarana_tid, $niveau_tid, $eleve_redouble);

            if ($saved != NULL) {
                drupal_set_message(t('Enregistrement reussi'));
            } else {
                drupal_set_message(t('Enregistrement echoé'), 'error');
            }
        }
    }
}

/**
 * ity no solon'ilay form rehefa mijery ny eleve
 * @param type $form
 * @param type $form_state
 * @param type $eleve_id
 * @return array
 */
function _ecoles_eleve_form_edit($form, &$form_state, $eleve_id) {

    if ($eleve_id != NULL && $eleve_id != 0) {

        try {

            $eleve = new EleveEleveWrapper($eleve_id);
            if ($eleve != NULL) {


                $form['#attributes'] = array(
                    'enctype' => 'multipart/form-data'
                );

                $form['eleve'] = array(
                    '#type' => 'fieldset',
                    '#title' => t('Information sur l\'eleve'),
                    '#prefix' => '<div class="eleve_main_view">',
                    '#suffix' => '</div>',
                );
                $form['eleve']['exist_photo'] = array(
                    '#type' => 'markup',
                    '#markup' => $eleve->getProfileImage(),
                    '#prefix' => '<div class="eleve_image">',
                    '#suffix' => '</div>',
                );

                $form['eleve']['num_mat'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Num Matricule'),
                    '#default_value' => $eleve->getNumMat(),
                    '#size' => '18',
                    '#prefix' => '<div class="right_in_fieldset">',
                    '#attributes' => array('readonly' => 'readonly'),
                        // any amin'ny sexe ity no mifarana
                );
                $form['eleve']['Nom'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Nom :'),
                    '#size' => '18',
                    '#default_value' => $eleve->getNom(),
                );
                $form['eleve']['prenom'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Prenom :'),
                    '#size' => '18',
                    '#default_value' => $eleve->getPrenom(),
                );

                $options = _get_taxonomy_term('sexe');
                $form['eleve']['sexe'] = array(
                    '#type' => 'select',
                    '#title' => t('Sexe'),
                    '#options' => $options,
                    '#default_value' => $eleve->getSex() != NULL ? $eleve->getSex()->tid : '',
                    '#attributes' => array('class' => array('sexe_select')),
                    '#suffix' => '</div>',
                );

                $form['eleve']['photo'] = array(
                    '#title' => t('Photo'),
                    '#type' => 'file',
                    '#weight' => 1,
                );

                $form['eleve']['date'] = array(
                    '#type' => 'date_popup',
                    '#title' => t('Date de naissance'),
                    '#size' => '18',
                    '#date_format' => 'd - M - Y',
                    '#date_year_range' => '-30:-10',
                    '#date_month_range' => '-:-',
                    '#date_label_position' => 'none',
                    '#required' => TRUE,
                    '#default_value' => date('Y-m-d', $eleve->getDateNaiss()),
                    '#attributes' => array('class' => array('date_create')),
                );

                $form['eleve']['lieu'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Lieu'),
                    '#size' => '18',
                    '#default_value' => $eleve->getLieu(),
                );
                $form['eleve']['adress'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Adress'),
                    '#size' => '18',
                    '#default_value' => $eleve->getAdress(),
                );
                $form['eleve']['tel'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Num tel'),
                    '#size' => '18',
                    '#default_value' => $eleve->getTel(),
                );

                // ----------- ity no ampidirana ny ray aman-dreny -------------
                $form['eleve_parent'] = array(
                    '#type' => 'fieldset',
                    '#title' => t('Information Parent'),
                    '#prefix' => '<div class="view_left">',
                    '#suffix' => '</div>',
                );

                $form['eleve_parent']['nom_pere'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Nom du père :'),
                    '#size' => '18',
                    '#default_value' => $eleve->getNomPere(),
                );

                $form['eleve_parent']['function_pere'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Fonction du père :'),
                    '#size' => '18',
                    '#default_value' => $eleve->getProfessionPere(),
                );

                $form['eleve_parent']['nom_mere'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Nom de la mère :'),
                    '#size' => '18',
                    '#default_value' => $eleve->getNomMere(),
                );

                $form['eleve_parent']['function_mere'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Fonction de la mère :'),
                    '#size' => '18',
                    '#default_value' => $eleve->getProfessionMere(),
                );

                $form['eleve_parent']['parent_adress'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Adresse de parent :'),
                    '#size' => '18',
                    '#default_value' => $eleve->getParentAdress(),
                );

                $form['eleve_parent']['nom_tuteur'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Nom du Tuteur :'),
                    '#size' => '18',
                    '#default_value' => $eleve != NULL ? $eleve->getNomTuteur() : '',
                );

                $form['eleve_parent']['function_tuteur'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Fonction du Tuteur :'),
                    '#size' => '18',
                    '#default_value' => $eleve != NULL ? $eleve->getProfessionTuteur() : '',
                );

                $form['eleve_parent']['num_tel_tuteur'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Numero Telephone du Tuteur :'),
                    '#size' => '18',
                    '#default_value' => $eleve != NULL ? $eleve->getNumTelTuteur() : '',
                );

                $form['eleve_parent']['adrres_tuteur'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Adresse du Tuteur :'),
                    '#size' => '18',
                    '#default_value' => $eleve != NULL ? $eleve->getAdressTuteur() : '',
                );

                // ----------- ity no ampidirana ny Niveau -------------
                $form['eleve_class'] = array(
                    '#type' => 'fieldset',
                    '#title' => t('Modification Classe'),
                    '#prefix' => '<div id="view_left" class="list_eleve">',
                    '#suffix' => '</div>',
                );

                $find_info = _look_up_eleve_in_eleve_taompianarana($eleve->getId());

                if ($find_info != NULL) {
                    $niveau = isset($find_info['NIVEAU_TID']) ? $find_info['NIVEAU_TID'] : NULL;
                    // rehefa mande ilay ajax dia miditra eto ilay izy
                    if (isset($form_state['values']['eleve_niveau'])) {
                        $niveau = $form_state['values']['eleve_niveau'];
                    }
                    $options_niveau = _get_taxonomy_term('niveau');
                    $options_niveau[NULL] = t('- Select -');

                    $form['eleve_class']['eleve_niveau'] = array(
                        '#type' => 'select',
                        '#title' => t('Niveau'),
                        '#options' => $options_niveau,
                        '#default_value' => $niveau,
                        '#ajax' => array(
                            'callback' => '_ajax_get_class_by_niveau_callback',
                            'wrapper' => 'view_left',
                        )
                    );

                    $options = ClasseTaxonomyTermWrapper::getClassByNiveau($niveau);
                    $options[NULL] = t('- Select -');

                    $form['eleve_class']['eleve_class'] = array(
                        '#type' => 'select',
                        '#title' => t('Classe'),
                        '#options' => $options,
                        '#default_value' => isset($find_info['CLASS_TID']) ? $find_info['CLASS_TID'] : NULL,
                    );

                    $form['eleve_class']['tetid'] = array(
                        '#type' => 'hidden',
                        '#value' => isset($find_info['ID']) ? $find_info['ID'] : NULL,
                    );
                }

                $form['submit'] = array(
                    '#type' => 'submit',
                    '#value' => t('Enregistrer la modification'),
                    '#prefix' => '<div class="list_eleve">',
                    '#suffix' => '</div>',
                );

                $form_state['destination_photo'] = FILE_PHOTO;
                $form_state['form_name'] = 'photo';

                $form['#attached']['css'][] = array('data' => drupal_get_path('module', 'entity_entity') . '/tools/css_entity.css', 'type' => 'file');
            }
        } catch (Exception $e) {
            $e->getMessage();
        }
    }
    return $form;
}

/**
 * 
 * ity ny submit ny modification
 * 
 * @param type $form
 * @param type $form_state
 */
function _ecoles_eleve_form_edit_submit($form, &$form_state) {

    $db_transaction = db_transaction();

    try {

        $values = $form_state['values'];

        $num_mat = $values['num_mat'];
        $nom = $values['Nom'];
        $prenom = $values['prenom'];
        $sexe = $values['sexe'];
        $date = $values['date'];
        $lieu = $values['lieu'];
        $adress = $values['adress'];
        $nom_pere = $values['nom_pere'];
        $function_pere = $values['function_pere'];
        $nom_mere = $values['nom_mere'];
        $parent_adress = $values['parent_adress'];
        $function_mere = $values['function_mere'];
        $tel = $values['tel'];
        $nom_tuteur = $values['nom_tuteur'];
        $function_tuteur = $values['function_tuteur'];
        $num_tel_tuteur = $values['num_tel_tuteur'];
        $adrres_tuteur = $values['adrres_tuteur'];


        $eleve = EleveEleveWrapper::getByNumMat($num_mat);

        $eleve->setNumMat($num_mat);
        $eleve->setTitle($num_mat);
        $eleve->setNom($nom);
        $eleve->setPrenom($prenom);
        $eleve->setSex($sexe);
        $eleve->setDateNaiss(strtotime($date));
        $eleve->setLieu($lieu);
        $eleve->setAdress($adress);
        $eleve->setTel($tel);
        $eleve->setNomPere($nom_pere);
        $eleve->setProfessionPere($function_pere);
        $eleve->setNomMere($nom_mere);
        $eleve->setProfessionMere($function_mere);
        $eleve->setParentAdress($parent_adress);
        $eleve->setNomTuteur($nom_tuteur);
        $eleve->setProfessionTuteur($function_tuteur);
        $eleve->setNumTelTuteur($num_tel_tuteur);
        $eleve->setAdressTuteur($adrres_tuteur);

        $source_file = _upload_photo($form, $form_state);

        // raha nisy ilay sary dia mditra eto
        if ($source_file != NULL) {
            $filePath = variable_get('PUBLIC_FILE', 'public://') . FILE_PHOTO;
            $photo_name = $eleve->getId() . '_' . $eleve->getNumMat();
            $dir = file_stream_wrapper_get_instance_by_uri($filePath)->realpath();
            $destination_file = $dir . '/' . $photo_name;
            $ext = NULL;
            // miditra eto amin'ity fonction ity no ahitana ny extension an'ilay image
            _upload_photo_compress_and_copy_image($source_file, $destination_file, $ext);

            if ($ext != NULL) {
                $eleve->setPhoto(array(PUBLIC_FILE . '/' . FILE_PHOTO . '/' . $photo_name . '.' . $ext));
            }
        }
        
        $eleve->save();

        // rehefa vita ny modification an'ilay eleve dia afaka modifier-na koa ny class sy niveau misy azy
        $table_id = $form_state['values']['tetid'];
        $eleve_class = $form_state['values']['eleve_class'];
        $eleve_niveau = $form_state['values']['eleve_niveau'];
        $info = _look_up_eleve_in_eleve_taompianarana($eleve->getId());

        if ($info != NULL) {

            if ((isset($info['CLASS_TID']) && $info['CLASS_TID'] != $eleve_class) ||
                    $info['NIVEAU_TID'] != $eleve_niveau ||
                    !isset($info['CLASS_TID']) && $eleve_class != NULL) {

                if ($table_id != NULL) {

                    if ($eleve_class != NULL) {

                        $class = new ClasseTaxonomyTermWrapper($eleve_class);

                        if ($class->getNiveau()->tid != $eleve_niveau) {

                            $db_transaction->rollback();
                            drupal_set_message(t('La class que vous avez selectionnée n\'est pas compatible avec ce niveau'), 'error');
                            drupal_set_message(t('Enregistrement echoé'), 'error');
                            return;
                        }
                    }
                    $fieldAndValue = array(
                        'niveau_tid' => $eleve_niveau,
                        'class_tid' => $eleve_class != NULL ? $eleve_class : NULL,
                    );
                    $conditions = array(
                        array(
                            'field_name' => 'id',
                            'value' => $table_id,
                            'operator' => '=',
                        )
                    );

                    if (_updateEleveTaompianarana($fieldAndValue, $conditions) != NULL) {
                        drupal_set_message(t('Enregistrement reussi'));
                    } else {
                        $db_transaction->rollback();
                        drupal_set_message(t('Enregistrement echoé'), 'error');
                    }
                }
            } else {
                drupal_set_message(t('Enregistrement reussi'));
            }
        } else {
            drupal_set_message(t('Enregistrement reussi'));
        }
    } catch (Exception $ex) {
        $db_transaction->rollback();
        drupal_set_message(t('Enregistrement echoé. Erreur : ' . $ex->getMessage()), 'error');
    }
}

function _ajax_get_class_by_niveau_callback($form, &$form_state) {
    $commands = array();

    $eleve_class = $form['eleve_class'];

    $commands[] = ajax_command_replace('#view_left', drupal_render($eleve_class));

    return array('#type' => 'ajax', '#commands' => $commands);
}



/**
 * Eto no manao ny generetion ny numero par classe
 * @param type $form
 * @param type $form_state
 * @return string
 */
function _ecoles_generate_num_en_class_eleve_form($form, &$form_state) {
    

    $form['#attributes'] = array(
        'enctype' => 'multipart/form-data'
    );

    $form['eleve'] = array(
        '#type'     => 'fieldset',
        '#title'    => t('Géneration de numero en classe de tous les élèves'),
        '#prefix'   => '<div class="eleve_main_view">',
        '#suffix'   => '</div>',
    );

    $options = array('NUM_MAT'=>'Numero Matricule','NOM' => 'Nom','PRENOM' => 'Prenom','DATE_NAISS' => 'Date de naissance');
    
    $form['eleve']['orderby'] = array(
        '#type' => 'select',
        '#title' => t('Ordre par'),
        '#options' => $options,
    );
    
    $form['eleve']['order'] = array(
        '#type' => 'select',
        '#title' => t('Ordre'),
        '#options' => array('ASC' => 'Ascendant','DESC' => 'Descendant'),
    );

    $form['eleve']['submit'] = array(
        '#type'     => 'submit',
        '#value'    => 'Génerer le numero'
    );

    return $form;
}



function _ecoles_generate_num_en_class_eleve_form_submit($form, $form_state) {
    
    $classes = _get_taxonomy_term('classe');
    $orderBy = $form_state['values']['orderby'];
    $order   = $form_state['values']['order'];
    $orderBy = array($order => $orderBy);
    
    foreach ($classes as $class_tid => $name) {
        
        $i   = 1;
        $sql = _eleve_sql_list_eleve($niveau_tid = NULL, $class_tid, variable_get('TAOMPIANARANA'), $nom_prenom = NULL, $num_mat = NULL, $sex = NULL, $orderBy);

        $result = db_query($sql);

        while ($record  = $result->fetchAssoc()) {
            
            $fieldAndValue = array('num_class' => $i++);
            
            $conditions = array(
                array(
                    'field_name' => 'id',
                    'value' => $record['TABLE_ID'],
                    'operator' => '=',
                )
            );
            _updateEleveTaompianarana($fieldAndValue, $conditions);
        }
    }
}