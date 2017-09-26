<?php
/**
 * @file
 * class RedoublementTaxonomyTermWrapper
 */

class RedoublementTaxonomyTermWrapper extends WdTaxonomyTermWrapper {

  protected $entity_type = 'taxonomy_term';
  private static $bundle = 'redoublement';

  /**
   * Create a new redoublement taxonomy_term.
   *
   * @param array $values
   * @param string $language
   * @return RedoublementTaxonomyTermWrapper
   */
  public static function create($values = array(), $language = LANGUAGE_NONE) {
    $values += array('entity_type' => 'taxonomy_term', 'bundle' => self::$bundle, 'type' => self::$bundle);
    $entity_wrapper = parent::create($values, $language);
    return new RedoublementTaxonomyTermWrapper($entity_wrapper->value());
  }

}