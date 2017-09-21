<?php
/**
 * @file
 * class ClasseTaxonomyTermWrapperQuery
 */

class ClasseTaxonomyTermWrapperQueryResults extends WdTaxonomyTermWrapperQueryResults {

  /**
   * @return ClasseTaxonomyTermWrapper
   */
  public function current() {
    return parent::current();
  }
}

class ClasseTaxonomyTermWrapperQuery extends WdTaxonomyTermWrapperQuery {

  private static $bundle = 'classe';

  /**
   * Construct a ClasseTaxonomyTermWrapperQuery
   */
  public function __construct() {
    parent::__construct('taxonomy_term');
    $this->byBundle(ClasseTaxonomyTermWrapperQuery::$bundle);
  }

  /**
   * Construct a ClasseTaxonomyTermWrapperQuery
   *
   * @return ClasseTaxonomyTermWrapperQuery
   */
  public static function find() {
    return new self();
  }

  /**
   * @return ClasseTaxonomyTermWrapperQueryResults
   */
  public function execute() {
    return new ClasseTaxonomyTermWrapperQueryResults($this->entityType, $this->query->execute());
  }

  /**
   * Query by field_niveau
   *
   * @param mixed $field_niveau
   * @param string $operator
   *
   * @return $this
   */
  public function byNiveau($field_niveau, $operator = NULL) {
    return $this->byFieldConditions(array('field_niveau' => array($field_niveau, $operator)));
  }

  /**
   * Order by field_niveau
   *
   * @param string $direction
   *
   * @return $this
   */
  public function orderByNiveau($direction = 'ASC') {
    return $this->orderByField('field_niveau.value', $direction);
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
