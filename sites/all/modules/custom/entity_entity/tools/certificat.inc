<?php

function certificat_de_scolarite($form, &$form_state, $eleve_id) {

    try {

        if ($eleve_id != NULL) {
            
            $eleve = new EleveEleveWrapper($eleve_id);
        }
        
    } catch (Exception $ex) {
        
    }
    return $form;
}
