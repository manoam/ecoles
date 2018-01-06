<?php

module_load_include('php', 'wrappers_custom', 'includes/taxonomy_term/ClasseTaxonomyTermWrapper');
module_load_include('php', 'wrappers_custom', 'includes/taxonomy_term/MatieresTaxonomyTermWrapper');
module_load_include('php', 'wrappers_custom', 'includes/taxonomy_term/TaompianaranaTaxonomyTermWrapper');

function _insertIntoClassMatieres($taompianarana_tid, $classe_tid, $matiere_tid, $prof_uid, $coeff) {

    if ($taompianarana_tid != NULL && $classe_tid != NULL && $matiere_tid != NULL && $prof_uid != NULL && $coeff != NULL) {

        try {

            $id = db_insert('classMatieres')->fields(array(
                        'taompianarana_tid' => $taompianarana_tid,
                        'classe_tid' => $classe_tid,
                        'matiere_tid' => $matiere_tid,
                        'prof_uid' => $prof_uid,
                        'coeff' => $coeff,
                            )
                    )
                    ->execute();

            // atao update eto ambany eto ireto mba ahafatarana oe efa nampiasaina
            // amin'izay tsy afaka atao modification intsony
            $matieres = new MatieresTaxonomyTermWrapper($matiere_tid);
            $matieres->setUsed(1);
            $matieres->save();

            $taompianarana = new TaompianaranaTaxonomyTermWrapper($taompianarana_tid);
            $taompianarana->setUsed(1);
            $taompianarana->save();

            $class = new NiveauTaxonomyTermWrapper($classe_tid);
            $class->setUsed(1);
            $class->save();

            return $id;
        } catch (Exception $ex) {
            drupal_set_message(t('[classMatieres::_insertIntoClassMatieres()] Erreur: @mess', array('@mess' => $ex->getMessage())), 'error');
        }
        return NULL;
    }
}

function _updateClassMatieres($fieldAndValue, $conditions) {

    if (count($fieldAndValue) != 0 && count($conditions) != 0) {

        try {

            $no_error = TRUE;
            $field = array(
                'id',
                'taompianarana_tid',
                'classe_tid',
                'matiere_tid',
                'prof_uid',
                'coeff',
            );

            //-- Tadiavina ao anatin'ny liste field aloha ilay $field ao @ condition sao tsy ao akory
            foreach ($fieldAndValue as $key => $value) {

                if (!in_array($key, $field)) {

                    $no_error = FALSE;
                    break;
                }
            }

            if ($no_error) {

                $query = db_update('classMatieres')
                        ->fields($fieldAndValue);

                foreach ($conditions as $predicate) {
                    $query->condition($predicate['field_name'], $predicate['value'], $predicate['operator']);
                }

                $id = $query->execute();

                if ($id != 0) {
                    //-- Tadiavina ao anatin'ny liste field aloha ilay $field ao @ condition sao tsy ao akory
                    foreach ($fieldAndValue as $key => $value) {

                        if ($key == 'matiere_tid' && $value != NULL) {
                            $matieres = new MatieresTaxonomyTermWrapper($matiere_tid);
                            $matieres->setUsed(1);
                            $matieres->save();
                        }
                        if ($key == 'taompianarana_tid' && $value != NULL) {
                            $taompianarana = new TaompianaranaTaxonomyTermWrapper($value);
                            $taompianarana->setUsed(1);
                            $taompianarana->save();
                        }
                        if ($key == 'class_tid' && $value != NULL) {
                            $class = new NiveauTaxonomyTermWrapper($value);
                            $class->setUsed(1);
                            $class->save();
                        }
                    }
                }
                return $id;
            }
        } catch (Exception $ex) {
            drupal_set_message(t($ex->getMessage()), 'error');
            return NULL;
        }
    }
}



function _selectFromClassMatieres($conditions = array(),$orderBy = 'matiere_tid') {
    
    try{

        $query = db_select('classMatieres', 't')
            ->fields('t',array(
                'id',
                'taompianarana_tid',
                'classe_tid',
                'matiere_tid',
                'prof_uid',
                'coeff',
                )       
            );

        foreach($conditions as $predicate){
            $query->condition('t.'.$predicate['field_name'], $predicate['value'],$predicate['operator']);
        }
        
        $query->orderBy('t.'.$orderBy, 'ASC');

        $result = $query->execute();

        return $result;

    }catch (Exception $ex){
        $message = t('[classMatieres::_selectFromClassMatieres()] Erreur: @mess', array('@mess' => $ex->getMessage())); 
        drupal_set_message($message, 'error');
    }
    return NULL;
    
}
