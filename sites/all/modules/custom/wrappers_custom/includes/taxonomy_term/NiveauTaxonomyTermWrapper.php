<?php

/**
 * @file
 * class NiveauTaxonomyTermWrapper
 */
class NiveauTaxonomyTermWrapper extends WdTaxonomyTermWrapper {

    protected $entity_type = 'taxonomy_term';
    private static $bundle = 'niveau';

    /**
     * Create a new niveau taxonomy_term.
     *
     * @param array $values
     * @param string $language
     * @return NiveauTaxonomyTermWrapper
     */
    public static function create($values = array(), $language = LANGUAGE_NONE) {
        $values += array('entity_type' => 'taxonomy_term', 'bundle' => self::$bundle, 'type' => self::$bundle);
        $entity_wrapper = parent::create($values, $language);
        return new NiveauTaxonomyTermWrapper($entity_wrapper->value());
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
    
    public static function getNiveauByCode($code) {
        
        if($code != NULL){
            
            $query = new EntityFieldQuery();
            $query->entityCondition('entity_type', 'taxonomy_term')
            ->entityCondition('bundle', 'niveau')
            ->fieldCondition('field_code', 'value', $code, '=');

            $tids = $query->execute();
            if (isset($tids['taxonomy_term'])) {
                $tids = array_keys($tids['taxonomy_term']);
                foreach ($tids as $tid){
                    return $tid;
                }
            }
        }
        return NULL;
    }

}
