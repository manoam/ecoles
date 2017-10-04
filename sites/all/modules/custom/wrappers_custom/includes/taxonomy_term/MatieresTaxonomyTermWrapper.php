<?php
/**
 * @file
 * class MatieresTaxonomyTermWrapper
 */

class MatieresTaxonomyTermWrapper extends WdTaxonomyTermWrapper {

  protected $entity_type = 'taxonomy_term';
  private static $bundle = 'matieres';

  /**
   * Create a new matieres taxonomy_term.
   *
   * @param array $values
   * @param string $language
   * @return MatieresTaxonomyTermWrapper
   */
  public static function create($values = array(), $language = LANGUAGE_NONE) {
    $values += array('entity_type' => 'taxonomy_term', 'bundle' => self::$bundle, 'type' => self::$bundle);
    $entity_wrapper = parent::create($values, $language);
    return new MatieresTaxonomyTermWrapper($entity_wrapper->value());
  }

}