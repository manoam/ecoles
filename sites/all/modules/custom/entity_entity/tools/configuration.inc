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
        '#title'        => t('Accée a la configuration '),
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
        '#prefix' => '<div class="eleve_main_view">',
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
        '#prefix' => '<div class="view_left">',
        '#suffix' => '</div>',
    );
    
            
    $form['export_import']['IMPORT_EXPORT_ACCESS'] = array(
        '#title'        => t('Type d\'utilisateur qui peut <b> <i> exporter et importer les listes des eleves </b> </i>'),
        '#type'         => 'select',
        '#multiple'     => TRUE,
        '#options'      => $roles_options,
        '#default_value'=> variable_get('IMPORT_EXPORT_ACCESS'),
    ) ;
    
    return system_settings_form($form);
}

