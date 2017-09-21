<?php

/**
 * @file
 * class TaompianaranaTaxonomyTermWrapper
 */
class TaompianaranaTaxonomyTermWrapper extends WdTaxonomyTermWrapper {

    protected $entity_type = 'taxonomy_term';
    private static $bundle = 'taompianarana';

    /**
     * Create a new taompianarana taxonomy_term.
     *
     * @param array $values
     * @param string $language
     * @return TaompianaranaTaxonomyTermWrapper
     */
    public static function create($values = array(), $language = LANGUAGE_NONE) {
        $values += array('entity_type' => 'taxonomy_term', 'bundle' => self::$bundle, 'type' => self::$bundle);
        $entity_wrapper = parent::create($values, $language);
        return new TaompianaranaTaxonomyTermWrapper($entity_wrapper->value());
    }

    /**
     * Sets field_start_date
     *
     * @param $value
     *
     * @return $this
     */
    public function setStartDate($value) {
        $this->set('field_start_date', $value);
        return $this;
    }

    /**
     * Retrieves field_start_date
     *
     * @return mixed
     */
    public function getStartDate() {
        return $this->get('field_start_date');
    }

    /**
     * Sets field_end_date
     *
     * @param $value
     *
     * @return $this
     */
    public function setEndDate($value) {
        $this->set('field_end_date', $value);
        return $this;
    }

    /**
     * Retrieves field_end_date
     *
     * @return mixed
     */
    public function getEndDate() {
        return $this->get('field_end_date');
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


    public static function add($name, $start_date, $end_date, $description = NULL) {

        if ($name != NULL && $start_date != NULL && $end_date != NULL) {

            try {
                $taompianarana = TaompianaranaTaxonomyTermWrapper::create();
                $taompianarana->setName($name);
                $taompianarana->setDescription($description);
                $taompianarana->setStartDate($start_date);
                $taompianarana->setEndDate($end_date);
                $taompianarana->setUsed(0);
                $taompianarana->save();
                
                return $taompianarana;
                
            } catch (Exception $ex) {

                drupal_set_message(t('Erreur de creation de taxonomy Taompianarana :' . $ex->getMessage()));
                return NULL;
            }
        }
        return NULL;
    }
}
