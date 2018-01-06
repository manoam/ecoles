<?php

/*
 * mi-setter ny variable get rehetra ilaina
 */
module_load_include('php', 'wrappers_custom', 'includes/taxonomy_term/PeriodTaxonomyTermWrapper');
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
        '#title'  => t('ANNEE SCOLAIRE'),
        '#type'   => 'fieldset',
        '#prefix' => '<div id="period_view" class="view_left">',
        '#suffix' => '</div>',
    );
    
    $options = _get_taxonomy_term('taompianarana');
            
    $form['taompianarana']['TAOMPIANARANA'] = array(
        '#title'        => t('Année Scolaire Courant: '),
        '#type'         => 'select',
        '#options'      => $options,
        '#default_value'=> variable_get('TAOMPIANARANA'),
        '#prefix'       =>'<div class = "copyright">',
        '#suffix'       => '</div>',
        '#ajax' => array(
            'callback' => '_ajax_get_period_by_taompianarana_callback',
        )
    ) ;
     
    $taompianarana_tid = variable_get('TAOMPIANARANA');
    
    if(isset($form_state['values']['TAOMPIANARANA'])){
        $taompianarana_tid = $form_state['values']['TAOMPIANARANA'];
    }
    
    $options = PeriodTaxonomyTermWrapper::getPeriodByTaompianarana($taompianarana_tid);
    
    $form['taompianarana']['PERIODE'] = array(
        '#title'        => t('Periode Courant: '),
        '#type'         => 'select',
        '#options'      => $options,
        '#prefix'       =>'<div class = "copyright">',
        '#suffix'       => '</div>',
        '#default_value'=> variable_get('PERIODE'),
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
    );
    
    $form['note'] = array(
        '#title'    => t('NOTE'),
        '#type'     => 'fieldset',
        '#prefix' => '<div class="eleve_main_view">',
        '#suffix' => '</div>',
    );
    
            
    $form['note']['VIEW_NOTE_PERMISSION'] = array(
        '#title'        => t('Type d\'utilisateur qui peut <b> <i> Modifier et inserer les notes des eleves </b> </i>'),
        '#type'         => 'select',
        '#multiple'     => TRUE,
        '#options'      => $roles_options,
        '#default_value'=> variable_get('VIEW_NOTE_PERMISSION'),
    ) ;
    
    $form['cisco_dren'] = array(
        '#title'    => t('Cisco et Dren'),
        '#type'     => 'fieldset',
        '#prefix' => '<div class="view_left">',// Natao an'ity rehefa misy vaovao eleve_main_view
        '#suffix' => '</div>',
    );
    
    $form['cisco_dren']['CISCO'] = array(
        '#title'        => t('Cisco : '),
        '#type'         => 'textfield',
        '#default_value'=> variable_get('CISCO'),
    ) ;
            
    $form['cisco_dren']['DREN'] = array(
        '#title'        => t('Dren : '),
        '#type'         => 'textfield',
        '#default_value'=> variable_get('DREN'),
    ) ;
    
    $form['cisco_dren']['ECOLE'] = array(
        '#title'        => t('Ecole : '),
        '#type'         => 'textfield',
        '#default_value'=> variable_get('ECOLE'),
    ) ;
    
    $form['cisco_dren']['CODE_ETAB'] = array(
        '#title'        => t('Code : '),
        '#type'         => 'textfield',
        '#default_value'=> variable_get('CODE_ETAB'),
    ) ;
    
    $form['faneva_mascar'] = array(
        '#title'    => t('Faneva'),
        '#type'     => 'fieldset',
        '#prefix' => '<div class="">',// Natao an'ity rehefa misy vaovao eleve_main_view
        '#suffix' => '</div>',
    );
    
    $form['faneva_mascar']['FANEVA_MASCAR'] = array(
        '#title'        => t('Faneva : '),
        '#type'         => 'textfield',
        '#default_value'=> variable_get('FANEVA_MASCAR'),
    ) ;
           
    return system_settings_form($form);
}


function _ajax_get_period_by_taompianarana_callback($form, &$form_state) {
    
    $commands = array();

    $taompianarana = $form['taompianarana'];

    $commands[] = ajax_command_replace('#period_view', drupal_render($taompianarana));
    return array('#type' => 'ajax', '#commands' => $commands);
}
