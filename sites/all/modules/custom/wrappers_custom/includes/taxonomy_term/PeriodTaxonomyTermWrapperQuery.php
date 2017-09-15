<?php
/**
 * @file
 * class PeriodTaxonomyTermWrapperQuery
 */

class PeriodTaxonomyTermWrapperQueryResults extends WdTaxonomyTermWrapperQueryResults {

  /**
   * @return PeriodTaxonomyTermWrapper
   */
  public function current() {
    return parent::current();
  }
}

class PeriodTaxonomyTermWrapperQuery extends WdTaxonomyTermWrapperQuery {

  private static $bundle = 'period';

  /**
   * Construct a PeriodTaxonomyTermWrapperQuery
   */
  public function __construct() {
    parent::__construct('taxonomy_term');
    $this->byBundle(PeriodTaxonomyTermWrapperQuery::$bundle);
  }

  /**
   * Construct a PeriodTaxonomyTermWrapperQuery
   *
   * @return PeriodTaxonomyTermWrapperQuery
   */
  public static function find() {
    return new self();
  }

  /**
   * @return PeriodTaxonomyTermWrapperQueryResults
   */
  public function execute() {
    return new PeriodTaxonomyTermWrapperQueryResults($this->entityType, $this->query->execute());
  }

  /**
   * Query by field_taompianarana
   *
   * @param mixed $field_taompianarana
   * @param string $operator
   *
   * @return $this
   */
  public function byTaompianarana($field_taompianarana, $operator = NULL) {
    return $this->byFieldConditions(array('field_taompianarana' => array($field_taompianarana, $operator)));
  }

  /**
   * Order by field_taompianarana
   *
   * @param string $direction
   *
   * @return $this
   */
  public function orderByTaompianarana($direction = 'ASC') {
    return $this->orderByField('field_taompianarana.value', $direction);
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

}
