<?php

/**
 * @file
 * class TypeDeNoteTaxonomyTermWrapper
 */
class TypeDeNoteTaxonomyTermWrapper extends WdTaxonomyTermWrapper {

    protected $entity_type = 'taxonomy_term';
    private static $bundle = 'type_de_note';

    /**
     * Create a new type_de_note taxonomy_term.
     *
     * @param array $values
     * @param string $language
     * @return TypeDeNoteTaxonomyTermWrapper
     */
    public static function create($values = array(), $language = LANGUAGE_NONE) {
        $values += array('entity_type' => 'taxonomy_term', 'bundle' => self::$bundle, 'type' => self::$bundle);
        $entity_wrapper = parent::create($values, $language);
        return new TypeDeNoteTaxonomyTermWrapper($entity_wrapper->value());
    }

    /**
     * Sets field_used
     *
     * @param $value
     *
     * @return $this
     */
    public function setUsed($value, $format = NULL) {
        $this->setText('field_used', $value, $format);
        return $this;
    }

    /**
     * Retrieves field_used
     *
     * @return mixed
     */
    public function getUsed($format = WdEntityWrapper::FORMAT_DEFAULT, $markup_format = NULL) {
        return $this->getText('field_used', $format, $markup_format);
    }

    public static function add($name, $description = NULL) {

        if ($name != NULL) {

            try {
                $typeDeNote = TypeDeNoteTaxonomyTermWrapper::create();
                $typeDeNote->setName($name);
                $typeDeNote->setDescription($description);
                $typeDeNote->setUsed(0);
                $typeDeNote->save();
                return $typeDeNote;
                
            } catch (Exception $ex) {

                drupal_set_message(t('Erreur de creation de taxonomy Type de note :' . $ex->getMessage()));
                return NULL;
            }
        }
        return NULL;
    }
}
