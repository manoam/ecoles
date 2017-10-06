<?php

module_load_include('inc', 'entity_entity', 'includes/relation/eleveNote');
module_load_include('php', 'wrappers_custom', 'includes/taxonomy_term/PeriodTaxonomyTermWrapper');
module_load_include('php', 'wrappers_custom', 'includes/taxonomy_term/TaompianaranaTaxonomyTermWrapper');

function _note_list_list_form($form, &$form_state) {

    $taompianara = new TaompianaranaTaxonomyTermWrapper(variable_get('TAOMPIANARANA'));

    $form['list']['title'] = array(
        '#type' => 'markup',
        '#markup' => t('Liste des notes des élèves année scolaire : ') . $taompianara->getName(),
        '#prefix' => '<div class = "uper_title">',
        '#suffix' => '</div>',
    );

    $form['filter'] = array(
        '#type' => 'fieldset',
        '#title' => t('Filtre'),
    );

    $options = _get_taxonomy_term('type_de_note');

    $form['filter']['type_note_tid'] = array(
        '#type' => 'select',
        '#title' => t('Type de note '),
        '#options' => $options,
        '#prefix' => '<div class = "copyright">',
        '#suffix' => '</div>',
    );

    $options = _get_taxonomy_term('classe');

    $form['filter']['class_tid'] = array(
        '#type' => 'select',
        '#title' => t('Classe'),
        '#options' => $options,
        '#prefix' => '<div class = "copyright">',
        '#suffix' => '</div>',
    );

    $options = _get_taxonomy_term('matieres');

    $form['filter']['matiere_tid'] = array(
        '#type' => 'select',
        '#title' => t('Matiere'),
        '#options' => $options,
        '#prefix' => '<div class = "copyright">',
        '#suffix' => '</div>',
    );

    $options = PeriodTaxonomyTermWrapper::getPeriodByTaompianarana(variable_get('TAOMPIANARANA'));

    $form['filter']['periode_tid'] = array(
        '#type' => 'select',
        '#title' => t('Periode'),
        '#options' => $options,
        '#prefix' => '<div class = "copyright">',
        '#suffix' => '</div>',
    );

    $form['filter']['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Filtrer'),
        '#prefix' => '<div class = "submit-filter">',
        '#suffix' => '</div>',
    );

    $header = array(
        t('Compteur'),
        t('Num Mat'),
        t('Nom'),
        t('Prénom'),
        t('Sexe'),
        t('Date de naissance'),
        t('Note / 20'),
    );

    $conditions = array();

    if (isset($form_state['matiere_tid'])) {

        $conditions[] = array(
            'field_name' => 'matiere_tid',
            'operator' => '=',
            'value' => $form_state['matiere_tid'],
        );
    }
    if (isset($form_state['class_tid'])) {

        $conditions[] = array(
            'field_name' => 'classe_tid',
            'operator' => '=',
            'value' => $form_state['class_tid'],
        );
    }
    if (isset($form_state['type_note_tid'])) {

        $conditions[] = array(
            'field_name' => 'type_note_tid',
            'operator' => '=',
            'value' => $form_state['type_note_tid'],
        );
    }
    if (isset($form_state['periode_tid'])) {

        $conditions[] = array(
            'field_name' => 'periode_tid',
            'operator' => '=',
            'value' => $form_state['periode_tid'],
        );
    }

    $result = NULL;

    if (count($conditions) != 0) {
        $result = _selectFromEleveNote($conditions);
    }

    if ($result != NULL) {

        $i = $result->rowCount();
        $rows = array();

        while ($note = $result->fetchAssoc()) {

            $eleve = new EleveEleveWrapper($note['eleve_tid']);
            $row = array();
            $row[] = $i--;

            $row[] = $eleve->getNumMat();
            $row[] = $eleve->getNom();
            $row[] = $eleve->getPrenom();
            $row[] = $eleve->getSex()->name;
            $row[] = date('d - M - Y', $eleve->getDateNaiss());
            $row[] = $note['note'];

            $rows[] = $row;
        }

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

function _note_list_list_form_submit($form, &$form_state) {

    $form_state['matiere_tid'] = $form_state['values']['matiere_tid'];
    $form_state['class_tid'] = $form_state['values']['class_tid'];
    $form_state['type_note_tid'] = $form_state['values']['type_note_tid'];
    $form_state['periode_tid'] = $form_state['values']['periode_tid'];

    $form_state['rebuild'] = 1;
}
