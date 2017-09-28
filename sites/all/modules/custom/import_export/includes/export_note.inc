<?php

function export_fiche_note_form($form, &$form_state) {

    $markup = t('<H1> EXPORT FICHE DE NOTE </H1>');


    $form['export_note'] = array(
        '#type' => 'markup',
        '#markup' => $markup,
        '#prefix' => '<div class="export_note" >',
        '#suffix' => '</div>',
    );


    $form['#attached']['css'][] = array('data' => drupal_get_path('module', 'entity_entity') . '/tools/css_entity.css', 'type' => 'file');
    return $form;
}
