<?php
/**
 * @file
 * class TaompianaranaTaxonomyTermWrapper
 */

class TaompianaranaTaxonomyTermWrapper extends WdTaxonomyTermWrapper {

  protected $entity_type = 'taxonomy_term';
  private static $bundle = 'taompianarana';

  /**
   * Create a new taompianarana taxonomy_term.
   *
   * @param array $values
   * @param string $language
   * @return TaompianaranaTaxonomyTermWrapper
   */
  public static function create($values = array(), $language = LANGUAGE_NONE) {
    $values += array('entity_type' => 'taxonomy_term', 'bundle' => self::$bundle, 'type' => self::$bundle);
    $entity_wrapper = parent::create($values, $language);
    return new TaompianaranaTaxonomyTermWrapper($entity_wrapper->value());
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
