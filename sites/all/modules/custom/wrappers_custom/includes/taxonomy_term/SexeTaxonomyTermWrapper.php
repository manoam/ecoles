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

}