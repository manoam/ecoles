<?php

module_load_include('php', 'wrappers_custom', 'includes/taxonomy_term/ClasseTaxonomyTermWrapper');
module_load_include('php', 'wrappers_custom', 'includes/taxonomy_term/MatieresTaxonomyTermWrapper');
module_load_include('php', 'wrappers_custom', 'includes/taxonomy_term/TaompianaranaTaxonomyTermWrapper');

function _insertIntoEleveNote($taompianarana_tid, $classe_tid, $matiere_tid, $eleve_id, $type_note_tid, $periode_tid, $note) {

    if ($taompianarana_tid != NULL &&
        $classe_tid != NULL &&
        $matiere_tid != NULL &&
        $eleve_id != NULL &&
        $type_note_tid != NULL &&
        $periode_tid != NULL &&
        $note != NULL) {

        try {

            $id = db_insert('eleveNote')->fields(array(
                        'taompianarana_tid' => $taompianarana_tid,
                        'classe_tid' => $classe_tid,
                        'matiere_tid' => $matiere_tid,
                        'eleve_id' => $eleve_id,
                        'type_note_tid' => $type_note_tid,
                        'periode_tid' => $periode_tid,
                        'note' => $note,
                            )
                    )
                    ->execute();

            return $id;
        } catch (Exception $ex) {
            drupal_set_message(t('[eleveNote::_insertIntoEleveNote()] Erreur: @mess', array('@mess' => $ex->getMessage())), 'error');
        }
        return NULL;
    }
}

function _updateEleveNote($fieldAndValue, $conditions) {

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

                $query = db_update('eleveNote')
                        ->fields($fieldAndValue);

                foreach ($conditions as $predicate) {
                    $query->condition($predicate['field_name'], $predicate['value'], $predicate['operator']);
                }

                return $query->execute();

            }
        } catch (Exception $ex) {
            drupal_set_message(t($ex->getMessage()), 'error');
            return NULL;
        }
    }
}
