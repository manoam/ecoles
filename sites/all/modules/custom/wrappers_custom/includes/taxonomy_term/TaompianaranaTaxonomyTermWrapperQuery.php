<?php
/**
 * @file
 * class TaompianaranaTaxonomyTermWrapperQuery
 */

class TaompianaranaTaxonomyTermWrapperQueryResults extends WdTaxonomyTermWrapperQueryResults {

  /**
   * @return TaompianaranaTaxonomyTermWrapper
   */
  public function current() {
    return parent::current();
  }
}

class TaompianaranaTaxonomyTermWrapperQuery extends WdTaxonomyTermWrapperQuery {

  private static $bundle = 'taompianarana';

  /**
   * Construct a TaompianaranaTaxonomyTermWrapperQuery
   */
  public function __construct() {
    parent::__construct('taxonomy_term');
    $this->byBundle(TaompianaranaTaxonomyTermWrapperQuery::$bundle);
  }

  /**
   * Construct a TaompianaranaTaxonomyTermWrapperQuery
   *
   * @return TaompianaranaTaxonomyTermWrapperQuery
   */
  public static function find() {
    return new self();
  }

  /**
   * @return TaompianaranaTaxonomyTermWrapperQueryResults
   */
  public function execute() {
    return new TaompianaranaTaxonomyTermWrapperQueryResults($this->entityType, $this->query->execute());
  }

  /**
   * Query by field_start_date
   *
   * @param mixed $field_start_date
   * @param string $operator
   *
   * @return $this
   */
  public function byStartDate($field_start_date, $operator = NULL) {
    return $this->byFieldConditions(array('field_start_date' => array($field_start_date, $operator)));
  }

  /**
   * Order by field_start_date
   *
   * @param string $direction
   *
   * @return $this
   */
  public function orderByStartDate($direction = 'ASC') {
    return $this->orderByField('field_start_date.value', $direction);
  }

  /**
   * Query by field_end_date
   *
   * @param mixed $field_end_date
   * @param string $operator
   *
   * @return $this
   */
  public function byEndDate($field_end_date, $operator = NULL) {
    return $this->byFieldConditions(array('field_end_date' => array($field_end_date, $operator)));
  }

  /**
   * Order by field_end_date
   *
   * @param string $direction
   *
   * @return $this
   */
  public function orderByEndDate($direction = 'ASC') {
    return $this->orderByField('field_end_date.value', $direction);
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
