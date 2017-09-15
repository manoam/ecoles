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

}