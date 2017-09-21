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

  /**
   * Query by field_code
   *
   * @param mixed $field_code
   * @param string $operator
   *
   * @return $this
   */
  public function byCode($field_code, $operator = NULL) {
    return $this->byFieldConditions(array('field_code' => array($field_code, $operator)));
  }

  /**
   * Order by field_code
   *
   * @param string $direction
   *
   * @return $this
   */
  public function orderByCode($direction = 'ASC') {
    return $this->orderByField('field_code.value', $direction);
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
