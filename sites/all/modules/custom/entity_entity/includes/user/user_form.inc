<?php

module_load_include('php', 'wrappers_custom', 'includes/user/UserUserWrapper');

function _user_form_form($form, &$form_state,$user_id) {
    
    if($user_id != NULL){
        
        $user = new UserUserWrapper($user_id);
        
        $form['user'] = array(
            '#type'=> 'fieldset',
        );
        
        $form['user']['nom'] = array(
            '#type'=> 'textfield',
        );
    }
    $form['#attached']['css'][] = array('data' => drupal_get_path('module', 'entity_entity') . '/tools/css_entity.css', 'type' => 'file');
    return $form;
}