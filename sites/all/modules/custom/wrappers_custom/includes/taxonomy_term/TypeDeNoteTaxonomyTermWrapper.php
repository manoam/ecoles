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

}