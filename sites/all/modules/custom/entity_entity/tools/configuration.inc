<?php

/*
 * mi-setter ny variable get rehetra ilaina
 */

module_load_include('php', 'wrappers_custom', 'includes/user/UserUserWrapper');

function configuration_form($form,&$form_state){
  
    $roles_options = UserUserWrapper::getAllRoles();
    
    $form['config'] = array(
        '#title'    => t('CONFIGURATION'),
        '#type'     => 'fieldset',
        '#prefix' => '<div class="eleve_main_view">',
        '#suffix' => '</div>',
    );
    
    $form['config']['CONFIGURATION'] = array(
        '#title'        => t('Accée à la configuration '),
        '#type'         => 'select',
        '#options'      => $roles_options,
        '#default_value'=> variable_get('CONFIGURATION'),
    ) ;
    
    $form['taompianarana'] = array(
        '#title'    => t('ANNEE SCOLAIRE'),
        '#type'     => 'fieldset',
        '#prefix' => '<div class="view_left">',
        '#suffix' => '</div>',
    );
    
    $options = _get_taxonomy_term('taompianarana');
            
    $form['taompianarana']['TAOMPIANARANA'] = array(
        '#title'        => t('Année Scolaire : '),
        '#type'         => 'select',
        '#options'      => $options,
        '#default_value'=> variable_get('TAOMPIANARANA'),
    ) ;
    
    
    $form['eleve'] = array(
        '#title'    => t('ELEVE'),
        '#type'     => 'fieldset',
        '#prefix' => '<div class="list_eleve">',
        '#suffix' => '</div>',
    );
    
            
    $form['eleve']['CREATE_ELEVE_PERMISSION'] = array(
        '#title'        => t('Type d\'utilisateur qui peut <b> <i> ajouter un élève </b> </i>'),
        '#type'         => 'select',
        '#multiple'     => TRUE,
        '#options'      => $roles_options,
        '#default_value'=> variable_get('CREATE_ELEVE_PERMISSION'),
    ) ;
    
    $form['eleve']['VOIR_LIST_ELEVE_PERMISSION'] = array(
        '#title'        => t('Type d\'utilisateur qui peut <b> <i>voir la liste des élève </b> </i>'),
        '#type'         => 'select',
        '#multiple'     => TRUE,
        '#options'      => $roles_options,
        '#default_value'=> variable_get('VOIR_LIST_ELEVE_PERMISSION'),
    ) ;
    
    $form['export_import'] = array(
        '#title'    => t('EXPORT / IMPORT'),
        '#type'     => 'fieldset',
        '#prefix' => '<div class="eleve_main_view">',
        '#suffix' => '</div>',
    );
    
            
    $form['export_import']['IMPORT_EXPORT_ACCESS'] = array(
        '#title'        => t('Type d\'utilisateur qui peut <b> <i> exporter et importer les listes des eleves </b> </i>'),
        '#type'         => 'select',
        '#multiple'     => TRUE,
        '#options'      => $roles_options,
        '#default_value'=> variable_get('IMPORT_EXPORT_ACCESS'),
    ) ;
    
    $form['taxonomy'] = array(
        '#title'    => t('TAXONOMY'),
        '#type'     => 'fieldset',
        '#prefix' => '<div class="view_left">',
        '#suffix' => '</div>',
    );
    
            
    $form['taxonomy']['VIEWS_TAXONOMY'] = array(
        '#title'        => t('Type d\'utilisateur qui peut <b> <i> Modifier et Voire la liste des utiles </b> </i>'),
        '#type'         => 'select',
        '#multiple'     => TRUE,
        '#options'      => $roles_options,
        '#default_value'=> variable_get('VIEWS_TAXONOMY'),
    ) ;
    
    $form['sisco_dren'] = array(
        '#title'    => t('Sisco et Dren'),
        '#type'     => 'fieldset',
        '#prefix' => '<div class="">',// atao an'ity rehefa misy vaovao eleve_main_view
        '#suffix' => '</div>',
    );
    
    $form['sisco_dren']['SISCO'] = array(
        '#title'        => t('Sisco : '),
        '#type'         => 'textfield',
        '#default_value'=> variable_get('SISCO'),
    ) ;
            
    $form['sisco_dren']['DREN'] = array(
        '#title'        => t('Dren : '),
        '#type'         => 'textfield',
        '#default_value'=> variable_get('DREN'),
    ) ;
    
    return system_settings_form($form);
}

