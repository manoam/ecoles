<?php
/**
 * @file
 * class TypeDeNoteTaxonomyTermWrapperQuery
 */

class TypeDeNoteTaxonomyTermWrapperQueryResults extends WdTaxonomyTermWrapperQueryResults {

  /**
   * @return TypeDeNoteTaxonomyTermWrapper
   */
  public function current() {
    return parent::current();
  }
}

class TypeDeNoteTaxonomyTermWrapperQuery extends WdTaxonomyTermWrapperQuery {

  private static $bundle = 'type_de_note';

  /**
   * Construct a TypeDeNoteTaxonomyTermWrapperQuery
   */
  public function __construct() {
    parent::__construct('taxonomy_term');
    $this->byBundle(TypeDeNoteTaxonomyTermWrapperQuery::$bundle);
  }

  /**
   * Construct a TypeDeNoteTaxonomyTermWrapperQuery
   *
   * @return TypeDeNoteTaxonomyTermWrapperQuery
   */
  public static function find() {
    return new self();
  }

  /**
   * @return TypeDeNoteTaxonomyTermWrapperQueryResults
   */
  public function execute() {
    return new TypeDeNoteTaxonomyTermWrapperQueryResults($this->entityType, $this->query->execute());
  }

}