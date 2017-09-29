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

}
