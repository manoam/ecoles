<?php
/**
 * @file
 * class MatieresTaxonomyTermWrapperQuery
 */

class MatieresTaxonomyTermWrapperQueryResults extends WdTaxonomyTermWrapperQueryResults {

  /**
   * @return MatieresTaxonomyTermWrapper
   */
  public function current() {
    return parent::current();
  }
}

class MatieresTaxonomyTermWrapperQuery extends WdTaxonomyTermWrapperQuery {

  private static $bundle = 'matieres';

  /**
   * Construct a MatieresTaxonomyTermWrapperQuery
   */
  public function __construct() {
    parent::__construct('taxonomy_term');
    $this->byBundle(MatieresTaxonomyTermWrapperQuery::$bundle);
  }

  /**
   * Construct a MatieresTaxonomyTermWrapperQuery
   *
   * @return MatieresTaxonomyTermWrapperQuery
   */
  public static function find() {
    return new self();
  }

  /**
   * @return MatieresTaxonomyTermWrapperQueryResults
   */
  public function execute() {
    return new MatieresTaxonomyTermWrapperQueryResults($this->entityType, $this->query->execute());
  }

}