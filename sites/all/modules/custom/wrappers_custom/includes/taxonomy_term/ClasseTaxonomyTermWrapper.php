<?php

/**
 * @file
 * class ClasseTaxonomyTermWrapper
 */
class ClasseTaxonomyTermWrapper extends WdTaxonomyTermWrapper {

    protected $entity_type = 'taxonomy_term';
    private static $bundle = 'classe';

    /**
     * Create a new classe taxonomy_term.
     *
     * @param array $values
     * @param string $language
     * @return ClasseTaxonomyTermWrapper
     */
    public static function create($values = array(), $language = LANGUAGE_NONE) {
        $values += array('entity_type' => 'taxonomy_term', 'bundle' => self::$bundle, 'type' => self::$bundle);
        $entity_wrapper = parent::create($values, $language);
        return new ClasseTaxonomyTermWrapper($entity_wrapper->value());
    }

    /**
     * Sets field_niveau
     *
     * @param $value
     *
     * @return $this
     */
    public function setNiveau($value) {
        $this->set('field_niveau', $value);
        return $this;
    }

    /**
     * Retrieves field_niveau
     *
     * @return mixed
     */
    public function getNiveau() {
        return $this->get('field_niveau');
    }

    /**
     * 
     * @param type $niveau_tid
     */
    public static function getClassByNiveau($niveau_tid) {

        $records = array();

        if ($niveau_tid != NULL) {

            $query = new EntityFieldQuery();

            $query->entityCondition('entity_type', 'taxonomy_term')
                    ->entityCondition('bundle', 'classe')
                    ->fieldCondition('field_niveau', 'tid', $niveau_tid, '=');

            $tids = $query->execute();

            if (isset($tids['taxonomy_term'])) {

                $tids = array_keys($tids['taxonomy_term']);

                foreach ($tids as $tid) {

                    $newterm = new ClasseTaxonomyTermWrapper($tid);

                    $records[intval($newterm->getTid())] = $newterm->getName();
                }
            }
        }

        return $records;
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

    public static function add($name, $niveau, $description = NULL) {

        if ($name != NULL && $niveau != NULL) {

            try {
                $period = ClasseTaxonomyTermWrapper::create();
                $period->setName($name);
                $period->setDescription($description);
                $period->setNiveau($niveau);
                $period->setUsed(0);
                $period->save();

                return $period;
            } catch (Exception $ex) {

                drupal_set_message(t('Erreur de creation de taxonomy Period :' . $ex->getMessage()));
                return NULL;
            }
        }
        return NULL;
    }

    public static function getClasseByCode($code) {

        if ($code != NULL) {

            $query = new EntityFieldQuery();
            $query->entityCondition('entity_type', 'taxonomy_term')
                    ->entityCondition('bundle', 'classe')
                    ->fieldCondition('field_code', 'value', $code, '=');

            $tids = $query->execute();
            if (isset($tids['taxonomy_term'])) {
                $tids = array_keys($tids['taxonomy_term']);
                foreach ($tids as $tid) {
                    return $tid;
                }
            }
        }
        return NULL;
    }

    /**
     * Sets field_code
     *
     * @param $value
     *
     * @return $this
     */
    public function setCode($value, $format = NULL) {
        $this->setText('field_code', $value, $format);
        return $this;
    }

    /**
     * Retrieves field_code
     *
     * @return mixed
     */
    public function getCode($format = WdEntityWrapper::FORMAT_DEFAULT, $markup_format = NULL) {
        return $this->getText('field_code', $format, $markup_format);
    }

}
