<?php

module_load_include('php', 'wrappers_custom', 'includes/group/GroupeGroupeWrapper');
module_load_include('php', 'wrappers_custom', 'includes/membre/MembreMembreWrapper');
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function _cecam_group_form($form, &$form_state, $group_id) {
    if ($group_id != NULL && $group_id != 0) {
        try {
            $group = new GroupeGroupeWrapper($group_id);
            if ($group != NULL) {
                $form['group'] = array(
                    '#type' => 'fieldset',
                    '#title' => t('Information sur le groupe'),
                    '#prefix' => '<div class="group_main_view">',
                    '#suffix' => '</div>',
                );
                $form['group']['Nom'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Nom de la groupe :'),
                    '#size' => '8',
                    '#value' => $group->getTitle(),
                    '#prefix' => '<div class="membre_view">',
                    '#attributes' => array('readonly' => 'readonly'),
                );
                $form['group']['Num'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Numero :'),
                    '#size' => '18',
                    '#value' => $group->getNum(),
                    '#attributes' => array('readonly' => 'readonly'),
                );
                $form['group']['Caisse'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Caisse :'),
                    '#size' => '18',
                    '#value' => $group->getCaisse()->name,
                    '#attributes' => array('readonly' => 'readonly'),
                );
                $form['group']['Lieu'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Lieu :'),
                    '#size' => '18',
                    '#value' => $group->getLieu(),
                    '#suffix' => '</div>',
                    '#attributes' => array('readonly' => 'readonly'),
                );


                // manomboka eto ny membre de bureau no aseho
                $form['bureau'] = array(
                    '#type' => 'fieldset',
                    '#title' => t('List des membres de bureau'),
                    '#prefix' => '<div class="bureau_list">',
                    '#suffix' => '</div>',
                );
                $bureaus = $group->getMembre();
                foreach ($bureaus as $bureau) {
                    $form['bureau']['membre'][] = array(
                        '#type' => 'textfield',
                        '#title' => t('Nom et Prénom :'),
                        '#size' => '18',
                        '#value' => $bureau->getNom() . ' ' . $bureau->getPrenom(),
                        '#attributes' => array('readonly' => 'readonly'),
                    );
                }

                $form['Membre'] = array(
                    '#type' => 'fieldset',
                    '#title' => t('List des membres ectuel de ce groupe'),
                    '#prefix' => '<div class="list_membre">',
                    '#suffix' => '</div>',
                );
            }
        } catch (Exception $ex) {
            
        }
    }
    return $form;
}

function _cecam_create_group_form($form, &$form_state) {
    try {
        if(empty($form_state['ajax_load'])){
            variable_set('list_membre', array());
            $form_state['ajax_load'] = 1;
        }
        $form['group'] = array(
            '#type' => 'fieldset',
            '#title' => t('Information sur le groupe'),
            '#prefix' => '<div class="group_main_view">',
            '#suffix' => '</div>',
        );
        $form['group']['Nom'] = array(
            '#type' => 'textfield',
            '#title' => t('Nom de la groupe :'),
            '#size' => '8',
            '#prefix' => '<div class="membre_view">',
        );
        $form['group']['Num'] = array(
            '#type' => 'textfield',
            '#title' => t('Numero de la groupe:'),
            '#size' => '18',
        );
        $form['group']['Caisse'] = array(
            '#type' => 'textfield',
            '#title' => t('Caisse :'),
            '#size' => '18',
        );
        $form['group']['Lieu'] = array(
            '#type' => 'textfield',
            '#title' => t('Lieu rensemblement:'),
            '#size' => '18',
            '#suffix' => '</div>',
        );


        // eto indray no ampidirina ny membre an'ilay group
        $form['new_membre'] = array(
            '#type' => 'fieldset',
            '#title' => t('Entrer ici les membres de ce groupe'),
            '#prefix' => '<div class="bureau_list" id="bureau_list">',
            '#suffix' => '</div>',
        );

        $form['new_membre']['membre'] = array(
            '#type' => 'textfield',
            '#title' => t('Numero CIN de la membre :'),
            '#size' => '18',
        );

        $form['new_membre']['button'] = array(
            '#type' => 'button',
            '#value' => t('Ajouter ce personne'),
            '#ajax' => array(
                'callback' => 'add_person_to_group_form',
            ),
        );

        $form['list_membre'] = array(
            '#type' => 'fieldset',
            '#title' => t('List des membres ectuel de ce groupe'),
            '#prefix' => '<div class="list_membre" id="list_membre">',
            '#suffix' => '</div>',
        );
        
        $new_membre = isset($form_state['values']['membre']) ? $form_state['values']['membre'] : NULL;
        $list_membres = variable_get('list_membre');
        if ($new_membre != NULL) {
            $new_membre = MembreMembreWrapper::titleLookUp($new_membre);
            if ($new_membre != NULL && !in_array($new_membre, $list_membres)) {
                $list_membres[] = $new_membre->getId();
            }
        }
        variable_set('list_membre', $list_membres);
        
        $header = array(
            array('data' => t('Nom'), 'class' => array()),
            array('data' => t('Prénom'), 'class' => array()),
            array('data' => t('CIN'), 'class' => array()),
            array('data' => t('Photo'), 'class' => array()),
        );
        
        $tableRows = array();
        foreach ($list_membres as $membreId) {
            $membreWrapper = new MembreMembreWrapper($membreId);
            if ($membreWrapper != NULL) {
                $tableRows[] = array(
                    array('data' => $membreWrapper->getNom(), 'class' => array()),
                    array('data' => $membreWrapper->getPrenom(), 'class' => array()),
                    array('data' => $membreWrapper->getTitle(), 'class' => array()),
                    array('data' => $membreWrapper->getCurentImageMembre($width = 100), 'class' => array()),
                );
            }
        }

        $form['list_membre']['table'] = array(
            '#theme' => 'table',
            '#header' => $header,
            '#rows' => $tableRows,
            '#empty' => NULL,
            '#attributes' => array('class' => array('qbtable'), 'id' => 'qbtable'),
        );

        return $form;
    } catch (Exception $ex) {
        
    }
}

function add_person_to_group_form($form, $form_state) {
    $commands = array();
    $bureau_list = $form['new_membre'];
    $list_membre = $form['list_membre'];

    $commands[] = ajax_command_replace('#list_membre', drupal_render($list_membre));
    $commands[] = ajax_command_replace('#bureau_list', drupal_render($bureau_list));
    return array('#type' => 'ajax', '#commands' => $commands);
}
