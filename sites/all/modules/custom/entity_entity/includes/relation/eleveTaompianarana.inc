<?php

module_load_include('php', 'wrappers_custom', 'includes/taxonomy_term/ClasseTaxonomyTermWrapper');
module_load_include('php', 'wrappers_custom', 'includes/taxonomy_term/NiveauTaxonomyTermWrapper');
module_load_include('php', 'wrappers_custom', 'includes/taxonomy_term/TaompianaranaTaxonomyTermWrapper');
function _insertIntoEleveTaompianarana($eleve_id, $taompianarana_tid, $niveau_tid, $class_tid = NULL) {

    if (
            $eleve_id != NULL &&
            $taompianarana_tid != NULL &&
            $niveau_tid != NULL
    ) {

        try {

            $id = db_insert('eleveTaompianarana')->fields(array(
                        'eleve_id' => $eleve_id,
                        'taompianarana_tid' => $taompianarana_tid,
                        'niveau_tid' => $niveau_tid,
                        'class_tid' => $class_tid,
                            )
                    )
                    ->execute();

            // atao update eto ambany eto ireto mba ahafatarana oe efa nampiasaina
            // amin'izay tsy afaka atao modification intsony
            $niveau = new NiveauTaxonomyTermWrapper($niveau_tid);
            $niveau->setUsed(1);
            $niveau->save();

            $taompianarana = new TaompianaranaTaxonomyTermWrapper($taompianarana_tid);
            $taompianarana->setUsed(1);
            $taompianarana->save();

            if ($class_tid != NULL) {
                $class = new NiveauTaxonomyTermWrapper($class_tid);
                $class->setUsed(1);
                $class->save();
            }

            return $id;
        } catch (Exception $ex) {
            drupal_set_message(t('[eleveTaompianarana::_insertIntoEleveTaompianarana()] Erreur: @mess', array('@mess' => $ex->getMessage())), 'error');
        }
        return NULL;
    }
}

function _updateEleveTaompianarana($fieldAndValue, $conditions) {

    if (count($fieldAndValue) != 0 && count($conditions) != 0) {

        try {

            $no_error = TRUE;
            $field = array(
                'id',
                'eleve_id',
                'taompianarana_tid',
                'niveau_tid',
                'class_tid',
            );

            //-- Tadiavina ao anatin'ny liste field aloha ilay $field ao @ condition sao tsy ao akory
            foreach ($fieldAndValue as $key => $value) {

                if (!in_array($key, $field)) {

                    $no_error = FALSE;
                    break;
                }
            }

            if ($no_error) {

                $query = db_update('eleveTaompianarana')
                        ->fields($fieldAndValue);

                foreach ($conditions as $predicate) {
                    $query->condition($predicate['field_name'], $predicate['value'], $predicate['operator']);
                }

                $id = $query->execute();

                if($id != 0){
                    //-- Tadiavina ao anatin'ny liste field aloha ilay $field ao @ condition sao tsy ao akory
                    foreach ($fieldAndValue as $key => $value) {

                        if ($key == 'niveau_tid' && $value != NULL) {
                            $niveau = new NiveauTaxonomyTermWrapper($value);
                            $niveau->setUsed(1);
                            $niveau->save();
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
