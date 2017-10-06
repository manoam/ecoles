<?php

module_load_include('php', 'wrappers_custom', 'includes/taxonomy_term/ClasseTaxonomyTermWrapper');
module_load_include('php', 'wrappers_custom', 'includes/taxonomy_term/MatieresTaxonomyTermWrapper');
module_load_include('php', 'wrappers_custom', 'includes/taxonomy_term/TaompianaranaTaxonomyTermWrapper');

function _insertIntoEleveNote($taompianarana_tid, $classe_tid, $matiere_tid, $eleve_id, $type_note_tid, $periode_tid, $note, $created_user) {

    if ($taompianarana_tid != NULL &&
            $classe_tid != NULL &&
            $matiere_tid != NULL &&
            $eleve_id != NULL &&
            $type_note_tid != NULL &&
            $periode_tid != NULL &&
            $note != NULL &&
            $created_user != NULL) {

        try {

            $id = db_insert('eleveNote')->fields(array(
                        'taompianarana_tid' => $taompianarana_tid,
                        'classe_tid' => $classe_tid,
                        'matiere_tid' => $matiere_tid,
                        'eleve_tid' => $eleve_id,
                        'type_note_tid' => $type_note_tid,
                        'periode_tid' => $periode_tid,
                        'note' => $note,
                        'created_date' => strtotime('now'),
                        'created_user' => $created_user,
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
                'eleve_tid',
                'type_note_tid',
                'periode_tid',
                'note',
                'created_date',
                'created_user',
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

function _selectFromEleveNote($conditions = array()) {

    try {

        $query = db_select('eleveNote', 't')
                ->fields('t', array(
            'id',
            'taompianarana_tid',
            'classe_tid',
            'matiere_tid',
            'eleve_tid',
            'type_note_tid',
            'periode_tid',
            'note',
                )
        );

        foreach ($conditions as $predicate) {
            $query->condition('t.' . $predicate['field_name'], $predicate['value'], $predicate['operator']);
        }

        $result = $query->execute();

        return $result;
    } catch (Exception $ex) {
        $message = t('[eleveNote::_selectFromEleveNote()] Erreur: @mess', array('@mess' => $ex->getMessage()));
        drupal_set_message($message, 'error');
    }
    return NULL;
}
