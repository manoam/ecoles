<?php

/**
 * @file
 * class SexeTaxonomyTermWrapper
 */
class SexeTaxonomyTermWrapper extends WdTaxonomyTermWrapper {

    protected $entity_type = 'taxonomy_term';
    private static $bundle = 'sexe';

    /**
     * Create a new sexe taxonomy_term.
     *
     * @param array $values
     * @param string $language
     * @return SexeTaxonomyTermWrapper
     */
    public static function create($values = array(), $language = LANGUAGE_NONE) {
        $values += array('entity_type' => 'taxonomy_term', 'bundle' => self::$bundle, 'type' => self::$bundle);
        $entity_wrapper = parent::create($values, $language);
        return new SexeTaxonomyTermWrapper($entity_wrapper->value());
    }

    public static function getClasseByName($name) {

        if ($name != NULL) {

            $query = new EntityFieldQuery();
            $query->entityCondition('entity_type', 'taxonomy_term')
                    ->entityCondition('bundle', 'sexe')
                    ->propertyCondition('name', $name, '=');

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
}
