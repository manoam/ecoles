<?php

/**
 * @file
 * class MatieresTaxonomyTermWrapper
 */
class MatieresTaxonomyTermWrapper extends WdTaxonomyTermWrapper {

    protected $entity_type = 'taxonomy_term';
    private static $bundle = 'matieres';

    /**
     * Create a new matieres taxonomy_term.
     *
     * @param array $values
     * @param string $language
     * @return MatieresTaxonomyTermWrapper
     */
    public static function create($values = array(), $language = LANGUAGE_NONE) {
        $values += array('entity_type' => 'taxonomy_term', 'bundle' => self::$bundle, 'type' => self::$bundle);
        $entity_wrapper = parent::create($values, $language);
        return new MatieresTaxonomyTermWrapper($entity_wrapper->value());
    }

    public static function add($name, $description = NULL) {

        if ($name != NULL) {

            try {
                $matieres = MatieresTaxonomyTermWrapper::create();
                $matieres->setName($name);
                $matieres->setDescription($description);
                $matieres->setUsed(0);
                $matieres->save();
                return $matieres;
            } catch (Exception $ex) {

                drupal_set_message(t('Erreur de creation de taxonomy matieres :' . $ex->getMessage()));
                return NULL;
            }
        }
        return NULL;
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

}
