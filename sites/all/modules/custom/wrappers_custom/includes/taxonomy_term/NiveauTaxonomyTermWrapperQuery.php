<?php
/**
 * @file
 * class NiveauTaxonomyTermWrapperQuery
 */

class NiveauTaxonomyTermWrapperQueryResults extends WdTaxonomyTermWrapperQueryResults {

  /**
   * @return NiveauTaxonomyTermWrapper
   */
  public function current() {
    return parent::current();
  }
}

class NiveauTaxonomyTermWrapperQuery extends WdTaxonomyTermWrapperQuery {

  private static $bundle = 'niveau';

  /**
   * Construct a NiveauTaxonomyTermWrapperQuery
   */
  public function __construct() {
    parent::__construct('taxonomy_term');
    $this->byBundle(NiveauTaxonomyTermWrapperQuery::$bundle);
  }

  /**
   * Construct a NiveauTaxonomyTermWrapperQuery
   *
   * @return NiveauTaxonomyTermWrapperQuery
   */
  public static function find() {
    return new self();
  }

  /**
   * @return NiveauTaxonomyTermWrapperQueryResults
   */
  public function execute() {
    return new NiveauTaxonomyTermWrapperQueryResults($this->entityType, $this->query->execute());
  }

}