<?php

module_load_include('php', 'wrappers_custom', 'includes/eleve/EleveEleveWrapper');
module_load_include('inc', 'entity_entity', 'includes/relation/eleveNote');

/**
 * 
 *  Ity fonction ity no manao ny calcule ny note isaky ny mpianatra arakaraka ny mode de calcul
 * 
 * @param type $eleve_id
 * @param type $mode_calcul
 * @return int
 */
function _note_calcul_note_sur_vingt($eleve_id, $mode_calcul, $classe_tid, $matiere_tid) {

    $total = 0;

    try {

        if ($eleve_id != NULL && $mode_calcul != NULL && $classe_tid != NULL && $matiere_tid != NULL) {

            $eleve = new EleveEleveWrapper($eleve_id);

            if ($eleve != NULL) {

                $type_de_note = _get_taxonomy_term('type_de_note');
                $type_note_array = array_keys($type_de_note);

                foreach ($type_note_array as $type_note) {

                    $conditions = array(
                        array(
                            'field_name' => 'taompianarana_tid',
                            'operator' => '=',
                            'value' => variable_get('TAOMPIANARANA'),
                        ),
                        array(
                            'field_name' => 'periode_tid',
                            'operator' => '=',
                            'value' => variable_get('PERIODE'),
                        ),
                        array(
                            'field_name' => 'classe_tid',
                            'operator' => '=',
                            'value' => $classe_tid,
                        ),
                        array(
                            'field_name' => 'matiere_tid',
                            'operator' => '=',
                            'value' => $matiere_tid,
                        ),
                        array(
                            'field_name' => 'type_note_tid',
                            'operator' => '=',
                            'value' => $type_note,
                        ),
                        array(
                            'field_name' => 'eleve_tid',
                            'operator' => '=',
                            'value' => $eleve_id,
                        ),
                    );

                    $note = 0;
                    $result = _selectFromEleveNote($conditions);

                    if ($result != NULL) {

                        while ($record = $result->fetchAssoc()) {

                            $note = $record['note'];
                        }
                    }

                    $mode_calcul = str_replace($type_note . '@', $note, $mode_calcul);
                }

                if ($mode_calcul != NULL) {

                    $mode_calcul = str_replace('#', '', $mode_calcul);
                    eval('$total = ' . $mode_calcul . ';');
                }
            }
        }
    } catch (Exception $ex) {

        drupal_set_message('[_note_calcul_note_sur_vingt] Erreur :' . $ex->getMessage(), 'error');
    }

    return $total;
}


/**
 * 
 * @param type $input
 * manao ny calcule ny note rehetra ampidirina ao anaty bulletin ity
 */
function note_calcul_generate_bulletin($input, &$total_note = 0, &$total_coeff = 0) {

    if (isset($input['ID']) && isset($input['CLASS_TID'])) {

        global $user;
        $eleve_id    = $input['ID'];
        $classe_tid  = $input['CLASS_TID'];

        // alaina amin'izay ny note rehetra isaky ny matiere an'ilay ankizy
        $conditions = array(
            array(
                'field_name' => 'taompianarana_tid',
                'operator' => '=',
                'value' => variable_get('TAOMPIANARANA'),
            ),
            array(
                'field_name' => 'classe_tid',
                'operator' => '=',
                'value' => $classe_tid,
            ),
        );

        $result_matiere = _selectFromClassMatieres($conditions);

        while ($record_matiere = $result_matiere->fetchAssoc()) {
            
            $total_coeff += $record_matiere['coeff'];
            $note_par_mat = 0;
            $conditions   = array(
                array(
                    'field_name' => 'taompianarana_tid',
                    'operator' => '=',
                    'value' => variable_get('TAOMPIANARANA'),
                ),
                array(
                    'field_name' => 'periode_tid',
                    'operator' => '=',
                    'value' => variable_get('PERIODE'),
                ),
                array(
                    'field_name' => 'classe_tid',
                    'operator' => '=',
                    'value' => $classe_tid,
                ),
                array(
                    'field_name' => 'matiere_tid',
                    'operator' => '=',
                    'value' => $record_matiere['matiere_tid'],
                ),
                array(
                    'field_name' => 'type_note_tid',
                    'operator' => '=',
                    'value' => variable_get('NOTE_SUR_20'),
                ),
                array(
                    'field_name' => 'eleve_tid',
                    'operator' => '=',
                    'value' => $eleve_id,
                ),
            );

            $result_note = _selectFromEleveNote($conditions);

            while ($record_note = $result_note->fetchAssoc()) {
                
                $note_par_mat = $record_note['note'];
            }
            
            _insertIntoEleveNote(variable_get('TAOMPIANARANA'), $classe_tid, $record_matiere['matiere_tid'], $eleve_id, variable_get('NOTE_DEFINITIF'), variable_get('PERIODE'), $note_par_mat * $record_matiere['coeff'], $user->uid);
            
            $total_note += $note_par_mat * $record_matiere['coeff'];
        }
        
        $moyen = $total_note / $total_coeff;
        // ilay '0' dia milaza oe moyenne generale sy toutes matiere
        _insertIntoEleveNote(variable_get('TAOMPIANARANA'), $classe_tid, '0', $eleve_id, '0', variable_get('PERIODE'), $moyen, $user->uid);
    }
}
