<?php

function list_taxonomy_list($form, &$form_state,$vocabulary) {
    
    $tags   = _get_taxonomy_term($vocabulary);
    $header = array(t('ID'), t('NOM'), t('VOIR'));
    $rows   = array();
    
    foreach ($tags as $key => $name) {
        $rows[] = array($key, $name,l(t('voir'),'ecoles/utile/'.$key));
    }
    if($vocabulary == 'taompianarana'){
        $vocabulary = t('Année scolaire');
    }
    
    $output  = '<div class="uper_title eleve_main_view"> Liste des : '.$vocabulary."</div>";
    $output .= '<div class="view_left text_right"><a href="/ecoles/utile/add/'.$vocabulary.'"> Ajouter nouveau </a> </div>';
    if(count($rows) != 0){
        $limit = 10;
        $current_table = pager_default_initialize(count($rows), $limit);
        $chunks = array_chunk($rows, $limit, TRUE);
        $output .= theme('table', array('header' => $header,'rows' => $chunks[$current_table],));
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
    