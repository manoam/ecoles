<?php
/**
 * @file
 * class SexeTaxonomyTermWrapperQuery
 */

class SexeTaxonomyTermWrapperQueryResults extends WdTaxonomyTermWrapperQueryResults {

  /**
   * @return SexeTaxonomyTermWrapper
   */
  public function current() {
    return parent::current();
  }
}

class SexeTaxonomyTermWrapperQuery extends WdTaxonomyTermWrapperQuery {

  private static $bundle = 'sexe';

  /**
   * Construct a SexeTaxonomyTermWrapperQuery
   */
  public function __construct() {
    parent::__construct('taxonomy_term');
    $this->byBundle(SexeTaxonomyTermWrapperQuery::$bundle);
  }

  /**
   * Construct a SexeTaxonomyTermWrapperQuery
   *
   * @return SexeTaxonomyTermWrapperQuery
   */
  public static function find() {
    return new self();
  }

  /**
   * @return SexeTaxonomyTermWrapperQueryResults
   */
  public function execute() {
    return new SexeTaxonomyTermWrapperQueryResults($this->entityType, $this->query->execute());
  }

}