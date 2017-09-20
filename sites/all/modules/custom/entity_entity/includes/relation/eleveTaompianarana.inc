<?php

function _insertIntoEleveTaompianarana($eleve_id, $taompianarana_tid, $niveau_tid, $class_tid = NULL) {

    if (
            $eleve_id != NULL &&
            $taompianarana_tid != NULL &&
            $niveau_tid != NULL
    ) {

        try {

            $id = db_insert('eleveTaompianarana')->fields(array(
                            'eleve_id'          => $eleve_id,
                            'taompianarana_tid' => $taompianarana_tid,
                            'niveau_tid'        => $niveau_tid,
                            'class_tid'         => $class_tid,
                        )
                    )
                    ->execute();

            return $id;
            
        } catch (Exception $ex) {
            drupal_set_message(t('[eleveTaompianarana::_insertIntoEleveTaompianarana()] Erreur: @mess', array('@mess' => $ex->getMessage())), 'error');
        }
        return NULL;
    }
}


function _updateEleveTaompianarana($fieldAndValue, $conditions) {
   
    if(count($fieldAndValue) != 0 && count($conditions) != 0){
    
        try{
            $no_error   = TRUE;
            $field      = array(
                        'id',
                        'eleve_id',
                        'taompianarana_tid',
                        'niveau_tid',
                        'class_tid',
                    );
            
            //-- Tadiavina ao anatin'ny liste field aloha ilay $field ao @ condition sao tsy ao akory
            foreach ($fieldAndValue as $key => $value) {
                
                if(!in_array($key, $field)){
                    
                    $no_error = FALSE;
                    break;
                }
            }
            
            if($no_error){
                
                $query = db_update('eleveTaompianarana')
                ->fields($fieldAndValue);
                
                foreach($conditions as $predicate){
                    $query->condition($predicate['field_name'], $predicate['value'],$predicate['operator']);
                }
                return $query->execute();
            }
            
        }catch (Exception $ex){
            drupal_set_message(t($ex->getMessage()), 'error');
            return NULL;
        }
    }
    
}