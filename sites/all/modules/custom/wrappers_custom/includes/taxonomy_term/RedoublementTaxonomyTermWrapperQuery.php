<?php
/**
 * @file
 * class RedoublementTaxonomyTermWrapperQuery
 */

class RedoublementTaxonomyTermWrapperQueryResults extends WdTaxonomyTermWrapperQueryResults {

  /**
   * @return RedoublementTaxonomyTermWrapper
   */
  public function current() {
    return parent::current();
  }
}

class RedoublementTaxonomyTermWrapperQuery extends WdTaxonomyTermWrapperQuery {

  private static $bundle = 'redoublement';

  /**
   * Construct a RedoublementTaxonomyTermWrapperQuery
   */
  public function __construct() {
    parent::__construct('taxonomy_term');
    $this->byBundle(RedoublementTaxonomyTermWrapperQuery::$bundle);
  }

  /**
   * Construct a RedoublementTaxonomyTermWrapperQuery
   *
   * @return RedoublementTaxonomyTermWrapperQuery
   */
  public static function find() {
    return new self();
  }

  /**
   * @return RedoublementTaxonomyTermWrapperQueryResults
   */
  public function execute() {
    return new RedoublementTaxonomyTermWrapperQueryResults($this->entityType, $this->query->execute());
  }

}