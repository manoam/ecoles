<?php

module_load_include('inc', 'entity_entity', 'includes/eleve/eleve_sql');
module_load_include('php', 'wrappers_custom', 'includes/taxonomy_term/ClasseTaxonomyTermWrapper');
module_load_include('php', 'wrappers_custom', 'includes/taxonomy_term/NiveauTaxonomyTermWrapper');

/**
 * 
 * @param type $taompianarana_tid
 * @param type $niveau_tid
 * @param type $class_tid
 * @return type
 */
function _eleve_list_get_list($niveau_tid = NULL,$class_tid = NULL,$taompianarana_tid = NULL) {
    
    $list = array();
    
    // raha NULL ity $taompianarana_tid ity dia ilay variable set no alina atao solony
    if($taompianarana_tid == NULL){
        $taompianarana_tid = variable_get('TAOMPIANARANA');
    }
    
    // ity no maka ny list ny eleve
    $sql = _eleve_sql_list_eleve($niveau_tid, $class_tid,$taompianarana_tid);
    
    $result = db_query($sql);
    
    while ($record  = $result->fetchAssoc()) {
        $list[]     = $record;
    }
    
    return $list;
}

function _eleve_list_list($form, &$form_state) {
    
    module_load_include('php', 'wrappers_custom', 'includes/taxonomy_term/TaompianaranaTaxonomyTermWrapper');
    
    $taompianara = new TaompianaranaTaxonomyTermWrapper(variable_get('TAOMPIANARANA'));
    
    $form['list']['title'] = array(
        '#type'     => 'markup',
        '#markup'   => t('Liste des élèves année scolaire : ').$taompianara->getName(),
        '#prefix'   => '<div class = "uper_title">',
        '#suffix'   => '</div>',
    );
    
    $form['filter'] = array(
        '#type' => 'fieldset',
        '#title'=> t('Filtre'),
    );
            
    $options        = _get_taxonomy_term('niveau');
    $options['']    = '-- tous --';
    
    $form['filter']['niveau'] = array(
        '#type'     => 'select',
        '#title'    => t('Niveau'),
        '#options'  => $options,
        '#prefix'   =>'<div class = "copyright">',
        '#suffix'   => '</div>',
    );
            
    $options        = _get_taxonomy_term('classe');
    $options['']    = '-- tous --';
    
    $form['filter']['class'] = array(
        '#type'     => 'select',
        '#title'    => t('Classe'),
        '#options'  => $options,
        '#prefix'   =>'<div class = "copyright">',
        '#suffix'   => '</div>',
    );
    
    $form['filter']['submit'] = array(
        '#type'     => 'submit',
        '#value'    => t('Filtrer'),
        '#prefix'   =>'<div class = "submit-filter">',
        '#suffix'   => '</div>',
    );
    
    $header = array(
        t('Compteur'),
        t('Num Mat'),
        t('Nom'),
        t('Prénom'),
        t('Sexe'),
        t('Date de naissance'),
        t('Niveau'),
        t('Classe'),
    );
    
    $niveau_tid = isset($form_state['niveau_tid'])? $form_state['niveau_tid'] : NULL;

    $class_tid = isset($form_state['class_tid'])? $form_state['class_tid'] : NULL;

    
    $list = _eleve_list_get_list($niveau_tid,$class_tid);
    
    $i    = count($list);
    $rows = array();
    
    foreach ($list as $eleve) {
        $row = array();
        $row[] = $i--;
        $row[] = $eleve['NUM_MAT'];
        $row[] = $eleve['NOM'];
        $row[] = $eleve['PRENOM'];
        $row[] = $eleve['SEXE'];
        $row[] = $eleve['DATE_NAISS'];
        $row[] = $eleve['NIVEAU_NAME'];
        $row[] = $eleve['CLASS_NAME'];
        
        $rows[] = $row;
    }
    
    $output = '';
    if(count($rows) != 0){
        //---------------------------------------------------------------//
        // eto no apetraka ny isan'ny aseho voalohany eo amin'ilay table //
        //---------------------------------------------------------------//
        $limit = 10;
        //---------------------------------------------------------------//
        // eto ny table ankehitriny na ny table miseho eo amin'ilay page //
        //---------------------------------------------------------------//
        $current_table = pager_default_initialize(count($rows), $limit);
        $chunks = array_chunk($rows, $limit, TRUE);
        //---------------------------------------------------------------//
        // ity no mametraka ilay tableau eo amin'ny page                 //
        //---------------------------------------------------------------//
        $output .= theme('table', array('header' => $header,'rows' => $chunks[$current_table],));
        //---------------------------------------------------------------------//
        //ity ilay manao ny isab'by page ery ambany sy manao next sy previews  //
        //---------------------------------------------------------------------//
        $output .= theme('pager', array('quantity', count($rows)));
    }else{
         $output .= theme('table', array('header' => $header,'rows' => array()));
    }
    $form['table'] = array(
        '#type' => 'markup',
        '#markup' => $output,
        '#prefix' => '<div id="">',
        '#suffix' => '</div>'
    );
    
    $form['#attached']['css'][] = array('data' => drupal_get_path('module', 'entity_entity') . '/tools/css_entity.css', 'type' => 'file');
    
    return $form;
}

function _eleve_list_list_submit($form , &$form_state) {
    
    $form_state['niveau_tid']     = $form_state['values']['niveau'];
    $form_state['class_tid']      = $form_state['values']['class'];
    
    $form_state['rebuild']        = 1;
}

function eleve_autocomplete_by_num_mat( $string = '') {
    
    $list = array();
    if($string != NULL){
        
        $query = _eleve_sql_get_by_num_mat($string);
        $result = db_query($query);
        
        while ($record = $result->fetchAssoc()) {
            $list[$record['NUM_MAT']] = $record['NUM_MAT'];
        }
    }
    
    drupal_json_output($list);
}

function _look_up_eleve_in_eleve_taompianarana($eleve_id) {
    
    if($eleve_id != NULL){

        $result = db_query(_look_up_eleve_in_eleve_taompianarana_sql($eleve_id));

        while ($record = $result->fetchAssoc()) {
            $niveauTerm = new NiveauTaxonomyTermWrapper($record['NIVEAU_TID']);
            $find_info['NIVEAU_TID']    = $niveauTerm->getTid();
            $find_info['NIVEAU_NAME']   = $niveauTerm->getName();
            $find_info['ID']   = $record['ID'];
            
            // mety mbola tsy nahazo class ilay ankizy
            if($record['CLASS_TID'] != NULL){
                $classTerm  = new ClasseTaxonomyTermWrapper($record['CLASS_TID']);
                $find_info['CLASS_TID']     = $classTerm->getTid();
                $find_info['CLASS_NAME']    = $classTerm->getName();
            }
            
            return $find_info;
        }
    }
    return NULL;
}

function _eleve_list_get_eleve_by_niveau($niveau_tid = NULL) {
    
    $list = array();

    // ity no maka ny list ny eleve
    $sql = _eleve_sql_list_eleve_by_niveau($niveau_tid);
    
    $result = db_query($sql);
    
    while ($record  = $result->fetchAssoc()) {
        $list[]     = $record;
    }
    
    return $list;
}


function _eleve_list_get_eleve_no_class($niveau_tid = NULL) {
    
    $list = array();

    // ity no maka ny list ny eleve
    $sql = _eleve_sql_list_eleve_no_class($niveau_tid);
    
    $result = db_query($sql);
    
    while ($record  = $result->fetchAssoc()) {
        $list[]     = $record;
    }
    
    return $list;
}


function _eleve_list_list_no_class($form, &$form_state) {
    
    module_load_include('php', 'wrappers_custom', 'includes/taxonomy_term/TaompianaranaTaxonomyTermWrapper');
    
    $taompianara = new TaompianaranaTaxonomyTermWrapper(variable_get('TAOMPIANARANA'));
    
    $form['list']['title'] = array(
        '#type'     => 'markup',
        '#markup'   => t('Liste des élèves no classée année scolaire : ').$taompianara->getName(),
        '#prefix'   => '<div class = "uper_title">',
        '#suffix'   => '</div>',
    );
    
    $form['filter'] = array(
        '#type' => 'fieldset',
        '#title'=> t('Filtre'),
    );
            
    $options        = _get_taxonomy_term('niveau');
    $options['']    = '-- tous --';
    
    $form['filter']['niveau'] = array(
        '#type'     => 'select',
        '#title'    => t('Niveau'),
        '#options'  => $options,
        '#prefix'   =>'<div class = "copyright">',
        '#suffix'   => '</div>',
    );
    
    $form['filter']['submit'] = array(
        '#type'     => 'submit',
        '#value'    => t('Filtrer'),
        '#prefix'   =>'<div class = "submit-filter">',
        '#suffix'   => '</div>',
    );
    
    $header = array(
        t('Compteur'),
        t('Num Mat'),
        t('Nom'),
        t('Prénom'),
        t('Sexe'),
        t('Date de naissance'),
        t('Niveau'),
        t('Voir'),
    );
    
    $niveau_tid = isset($form_state['niveau_tid'])? $form_state['niveau_tid'] : NULL;
    
    $rows = array();
    
    // ity no maka ny list ny eleve
    $sql = _eleve_sql_list_eleve_no_class($niveau_tid);
    
    $result = db_query($sql);
    
    $i    = $result->rowCount();
    
    while ($eleve  = $result->fetchAssoc()) {
        
        $row = array();
        $row[] = $i--;
        $row[] = $eleve['NUM_MAT'];
        $row[] = $eleve['NOM'];
        $row[] = $eleve['PRENOM'];
        $row[] = $eleve['SEXE'];
        $row[] = $eleve['DATE_NAISS'];
        $row[] = $eleve['NIVEAU_NAME'];
        $row[] = l('voir','eleve/eleve/'.$eleve['ID']);
        
        $rows[] = $row;
    }
    
    $output = '';
    if(count($rows) != 0){
        //---------------------------------------------------------------//
        // eto no apetraka ny isan'ny aseho voalohany eo amin'ilay table //
        //---------------------------------------------------------------//
        $limit = 10;
        //---------------------------------------------------------------//
        // eto ny table ankehitriny na ny table miseho eo amin'ilay page //
        //---------------------------------------------------------------//
        $current_table = pager_default_initialize(count($rows), $limit);
        $chunks = array_chunk($rows, $limit, TRUE);
        //---------------------------------------------------------------//
        // ity no mametraka ilay tableau eo amin'ny page                 //
        //---------------------------------------------------------------//
        $output .= theme('table', array('header' => $header,'rows' => $chunks[$current_table],));
        //---------------------------------------------------------------------//
        //ity ilay manao ny isab'by page ery ambany sy manao next sy previews  //
        //---------------------------------------------------------------------//
        $output .= theme('pager', array('quantity', count($rows)));
    }else{
         $output .= theme('table', array('header' => $header,'rows' => array()));
    }
    $form['table'] = array(
        '#type' => 'markup',
        '#markup' => $output,
        '#prefix' => '<div id="relationtable">',
        '#suffix' => '</div>'
    );
    
    $form['#attached']['css'][] = array('data' => drupal_get_path('module', 'entity_entity') . '/tools/css_entity.css', 'type' => 'file');
    
    return $form;
}

function _eleve_list_list_no_class_submit($form , &$form_state) {
    
    $form_state['niveau_tid']     = $form_state['values']['niveau'];
    
    $form_state['rebuild']        = 1;
}

