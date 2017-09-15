<?php

function _taxonomy_load_form($form, &$form_state, $tid) {

    if ($tid != NULL && $tid != 0) {

        try {

            $tag = new WdTaxonomyTermWrapper($tid);
            
            if ($tag != NULL) {
                
                $form_state['tid'] = $tid;

                $form['taxonomy'] = array(
                    '#type' => 'fieldset',
                    '#title' => t('Taxonomy : '.$tag->getBundle()),
                );
                
                $form['taxonomy']['name'] = array(
                    '#type' => 'textfield',
                    '#title'=> t('Nom : '),
                    '#default_value' => $tag->getName(),
                );
                
                $form['taxonomy']['description'] = array(
                    '#type' => 'textarea',
                    '#title'=> t('Description : '),
                    '#default_value' => str_replace(array('<p>','</p>'), array('',''), $tag->getDescription()),
                );
                
                $form['taxonomy']['submit'] = array(
                    '#type' => 'submit',
                    '#value'=> t('Enregistrer les modification'),
                );
            }
        }  catch (Exception $e){
            
        }
    }
    return $form;
}

function _taxonomy_load_form_submit($form , &$form_state) {
    
    $tag = new WdTaxonomyTermWrapper($form_state['tid']);
    $tag->setName($form_state['values']['name']);
    $tag->setDescription($form_state['values']['description']);
    $tag->save();
}