<?php
/**
 * @file
 * class TagsTaxonomyTermWrapper
 */

class TagsTaxonomyTermWrapper extends WdTaxonomyTermWrapper {

  protected $entity_type = 'taxonomy_term';
  private static $bundle = 'tags';

  /**
   * Create a new tags taxonomy_term.
   *
   * @param array $values
   * @param string $language
   * @return TagsTaxonomyTermWrapper
   */
  public static function create($values = array(), $language = LANGUAGE_NONE) {
    $values += array('entity_type' => 'taxonomy_term', 'bundle' => self::$bundle, 'type' => self::$bundle);
    $entity_wrapper = parent::create($values, $language);
    return new TagsTaxonomyTermWrapper($entity_wrapper->value());
  }

}