<?php

function fiche_note_form($form, &$form_state) {

    // ity no eo amin'ny voalohany apovoany
    $markup = t('<div class="entete_center"><H3>REPOBLIKAN\'I MADAGASIKARA</H3><div class="">');
    $markup.= variable_get('FANEVA_MASCAR');
    $markup.= t('</br>**************************</div></div>');
    
    // ity no eo amin'ny sisiny ankavia
    $markup.= t('<div class="entete_left">');
    $markup.= t('<H3>DIRECTION REGIONAL DES ENSEIGNEMENT </H3>');
    $markup.= variable_get('DREN');
    $markup.= t('<H3>CIRCONSCRIPTION SCOLAIRE </H3>');
    $markup.= variable_get('CISCO');
    $markup.= t('</div>');
    
    
    $markup.= t('<div class="entete_right"><H3>ANNEE SCOLAIRE : </H3>');
    $markup.= variable_get('CISCO');
    $markup.= t('</div>');

    $markup.= t('<div class="entete_name">BULLETIN DE NOTES</div>');
    
    $markup.= t('<div class="entete_title"><H1> FICHE DE NOTE </H1></div>');
    
    $form['note'] = array(
        '#type' => 'markup',
        '#markup' => $markup,
    );
    
    $form['note_2'] = array(
        '#type' => 'container',
        '#prefix' => '<div class="list_eleve" >',
        '#suffix' => '</div>',
    );
    
    $form['note_2']['nom_prenom'] = array(
        '#type' => 'markup',
        '#markup'=> t("<b>Nom et prénom :</b>"),
        '#prefix' => '<div class="" >',
    );

    $form['note_2']['date_naiss'] = array(
        '#type' => 'markup',
        '#markup'=> t("<b>Date de naissance :</b>"),
        '#prefix' => '</br>',
    );
    
    $form['note_2']['num_mat'] = array(
        '#type' => 'markup',
        '#markup'=> t("<b>Matricule :</b>"),
        '#prefix' => '</br>',
        '#suffix' => '</div>',
    );
    
    $form['note_2']['sex'] = array(
        '#type' => 'markup',
        '#markup'=> t("<b>Sexe :</b>"),
        '#prefix' => '<div class="entete_title" >',
    );

    $form['note_2']['class'] = array(
        '#type' => 'markup',
        '#markup'=> t("<b>Classe :</b>"),
        '#prefix' => '</br>',
        '#suffix' => '</div>',
    );

    $form['note_2']['numero'] = array(
        '#type' => 'markup',
        '#markup'=> t("<b>Numero :</b>"),
        '#prefix' => '<div class="entete_right" >',
    );

    $form['note_2']['effectif'] = array(
        '#type' => 'markup',
        '#markup'=> t("<b>Effectif :</b>"),
        '#prefix' => '</br>',
        '#suffix' => '</div>',
    );

    $form['#attached']['css'][] = array('data' => drupal_get_path('module', 'entity_entity') . '/tools/css_entity.css', 'type' => 'file');
    
    if(isset($_GET['pdf']) && $_GET['pdf'] == 1){
        drupal_add_css(drupal_get_path('module', 'entity_entity').'/tools/css_to_pdf.css');
    }
    return $form;
}
