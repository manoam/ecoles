<?php
/**
 * @file
 * class TagsTaxonomyTermWrapperQuery
 */

class TagsTaxonomyTermWrapperQueryResults extends WdTaxonomyTermWrapperQueryResults {

  /**
   * @return TagsTaxonomyTermWrapper
   */
  public function current() {
    return parent::current();
  }
}

class TagsTaxonomyTermWrapperQuery extends WdTaxonomyTermWrapperQuery {

  private static $bundle = 'tags';

  /**
   * Construct a TagsTaxonomyTermWrapperQuery
   */
  public function __construct() {
    parent::__construct('taxonomy_term');
    $this->byBundle(TagsTaxonomyTermWrapperQuery::$bundle);
  }

  /**
   * Construct a TagsTaxonomyTermWrapperQuery
   *
   * @return TagsTaxonomyTermWrapperQuery
   */
  public static function find() {
    return new self();
  }

  /**
   * @return TagsTaxonomyTermWrapperQueryResults
   */
  public function execute() {
    return new TagsTaxonomyTermWrapperQueryResults($this->entityType, $this->query->execute());
  }

}