<?php

function export_fiche_note_form($form, &$form_state) {

    $markup = t('<H1> FICHE DE NOTE </H1>');
    $markup.= t('<H3>REPOBLIKAN\'I MADAGASIKARA</H3><div class="">');
    $markup.= variable_get('');
    $markup.= t('</div>');
    

    $form['export_note'] = array(
        '#type' => 'markup',
        '#markup' => $markup,
        '#prefix' => '<div class="export_note" >',
        '#suffix' => '</div>',
    );
    

    $form['#attached']['css'][] = array('data' => drupal_get_path('module', 'entity_entity') . '/tools/css_entity.css', 'type' => 'file');
    return $form;
}
