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

  /**
   * Query by field_used
   *
   * @param mixed $field_used
   * @param string $operator
   *
   * @return $this
   */
  public function byUsed($field_used, $operator = NULL) {
    return $this->byFieldConditions(array('field_used' => array($field_used, $operator)));
  }

  /**
   * Order by field_used
   *
   * @param string $direction
   *
   * @return $this
   */
  public function orderByUsed($direction = 'ASC') {
    return $this->orderByField('field_used.value', $direction);
  }

}
