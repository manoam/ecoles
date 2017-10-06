<?php

/**
 * @file
 * class PeriodTaxonomyTermWrapper
 */
class PeriodTaxonomyTermWrapper extends WdTaxonomyTermWrapper {

    protected $entity_type = 'taxonomy_term';
    private static $bundle = 'period';

    /**
     * Create a new period taxonomy_term.
     *
     * @param array $values
     * @param string $language
     * @return PeriodTaxonomyTermWrapper
     */
    public static function create($values = array(), $language = LANGUAGE_NONE) {
        $values += array('entity_type' => 'taxonomy_term', 'bundle' => self::$bundle, 'type' => self::$bundle);
        $entity_wrapper = parent::create($values, $language);
        return new PeriodTaxonomyTermWrapper($entity_wrapper->value());
    }

    /**
     * Sets field_taompianarana
     *
     * @param $value
     *
     * @return $this
     */
    public function setTaompianarana($value) {
        $this->set('field_taompianarana', $value);
        return $this;
    }

    /**
     * Retrieves field_taompianarana
     *
     * @return mixed
     */
    public function getTaompianarana() {
        return $this->get('field_taompianarana');
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


    public static function add($name, $taompianarana_tid, $start_date, $end_date, $description = NULL) {

        if ($name != NULL && $taompianarana_tid != NULL && $start_date != NULL && $end_date != NULL) {

            try {
                $period = PeriodTaxonomyTermWrapper::create();
                $period->setName($name);
                $period->setDescription($description);
                $period->setTaompianarana($taompianarana_tid);
                $period->setStartDate($start_date);
                $period->setEndDate($end_date);
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
    
    
    /**
     * 
     * @param type $taompianarana_tid
     */
    public static function getPeriodByTaompianarana($taompianarana_tid) {

        $records = array();

        if ($taompianarana_tid != NULL) {

            $query = new EntityFieldQuery();

            $query->entityCondition('entity_type', 'taxonomy_term')
                    ->entityCondition('bundle', 'period')
                    ->fieldCondition('field_taompianarana', 'tid', $taompianarana_tid, '=');

            $tids = $query->execute();

            if (isset($tids['taxonomy_term'])) {

                $tids = array_keys($tids['taxonomy_term']);

                foreach ($tids as $tid) {

                    $newterm = new PeriodTaxonomyTermWrapper($tid);

                    $records[intval($newterm->getTid())] = $newterm->getName();
                }
            }
        }

        return $records;
    }
}
