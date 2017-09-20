<?php
/**
 * @file
 * class PeriodTaxonomyTermWrapper
 */

class PeriodTaxonomyTermWrapper extends WdTaxonomyTermWrapper {

  protected $entity_type = 'taxonomy_term';
  private static $bundle = 'period';

  /**
   * Create a new period taxonomy_term.
   *
   * @param array $values
   * @param string $language
   * @return PeriodTaxonomyTermWrapper
   */
  public static function create($values = array(), $language = LANGUAGE_NONE) {
    $values += array('entity_type' => 'taxonomy_term', 'bundle' => self::$bundle, 'type' => self::$bundle);
    $entity_wrapper = parent::create($values, $language);
    return new PeriodTaxonomyTermWrapper($entity_wrapper->value());
  }

  /**
   * Sets field_taompianarana
   *
   * @param $value
   *
   * @return $this
   */
  public function setTaompianarana($value) {
    $this->set('field_taompianarana', $value);
    return $this;
  }

  /**
   * Retrieves field_taompianarana
   *
   * @return mixed
   */
  public function getTaompianarana() {
    return $this->get('field_taompianarana');
  }

  /**
   * Sets field_start_date
   *
   * @param $value
   *
   * @return $this
   */
  public function setStartDate($value) {
    $this->set('field_start_date', $value);
    return $this;
  }

  /**
   * Retrieves field_start_date
   *
   * @return mixed
   */
  public function getStartDate() {
    return $this->get('field_start_date');
  }

  /**
   * Sets field_end_date
   *
   * @param $value
   *
   * @return $this
   */
  public function setEndDate($value) {
    $this->set('field_end_date', $value);
    return $this;
  }

  /**
   * Retrieves field_end_date
   *
   * @return mixed
   */
  public function getEndDate() {
    return $this->get('field_end_date');
  }

}
