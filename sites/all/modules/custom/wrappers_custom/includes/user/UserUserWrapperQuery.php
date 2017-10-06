<?php
/**
 * @file
 * class UserUserWrapperQuery
 */

class UserUserWrapperQueryResults extends WdUserWrapperQueryResults {

  /**
   * @return UserUserWrapper
   */
  public function current() {
    return parent::current();
  }
}

class UserUserWrapperQuery extends WdUserWrapperQuery {

  private static $bundle = 'user';

  /**
   * Construct a UserUserWrapperQuery
   */
  public function __construct() {
    parent::__construct('user');
    $this->byBundle(UserUserWrapperQuery::$bundle);
  }

  /**
   * Construct a UserUserWrapperQuery
   *
   * @return UserUserWrapperQuery
   */
  public static function find() {
    return new self();
  }

  /**
   * @return UserUserWrapperQueryResults
   */
  public function execute() {
    return new UserUserWrapperQueryResults($this->entityType, $this->query->execute());
  }

  /**
   * Query by field_nom
   *
   * @param mixed $field_nom
   * @param string $operator
   *
   * @return $this
   */
  public function byNom($field_nom, $operator = NULL) {
    return $this->byFieldConditions(array('field_nom' => array($field_nom, $operator)));
  }

  /**
   * Order by field_nom
   *
   * @param string $direction
   *
   * @return $this
   */
  public function orderByNom($direction = 'ASC') {
    return $this->orderByField('field_nom.value', $direction);
  }

  /**
   * Query by field_tel
   *
   * @param mixed $field_tel
   * @param string $operator
   *
   * @return $this
   */
  public function byTel($field_tel, $operator = NULL) {
    return $this->byFieldConditions(array('field_tel' => array($field_tel, $operator)));
  }

  /**
   * Order by field_tel
   *
   * @param string $direction
   *
   * @return $this
   */
  public function orderByTel($direction = 'ASC') {
    return $this->orderByField('field_tel.value', $direction);
  }

  /**
   * Query by field_adress
   *
   * @param mixed $field_adress
   * @param string $operator
   *
   * @return $this
   */
  public function byAdress($field_adress, $operator = NULL) {
    return $this->byFieldConditions(array('field_adress' => array($field_adress, $operator)));
  }

  /**
   * Order by field_adress
   *
   * @param string $direction
   *
   * @return $this
   */
  public function orderByAdress($direction = 'ASC') {
    return $this->orderByField('field_adress.value', $direction);
  }

  /**
   * Query by field_image
   *
   * @param mixed $field_image
   * @param string $operator
   *
   * @return $this
   */
  public function byImage($field_image, $operator = NULL) {
    if (is_object($field_image) && !empty($field_image->fid)) {
      $fid = $field_image->fid;
    }
    elseif (is_array($field_image) && !empty($field_image['fid'])) {
      $fid = $field_image['fid'];
    }
    else {
      $fid = $field_image;
    }
    return $this->byFieldConditions(array('field_image.fid' => array($field_image, $operator)));
  }

  /**
   * Order by field_image
   *
   * @param string $direction
   *
   * @return $this
   */
  public function orderByImage($direction = 'ASC') {
    return $this->orderByField('field_image.fid', $direction);
  }

  /**
   * Query by field_sex
   *
   * @param mixed $field_sex
   * @param string $operator
   *
   * @return $this
   */
  public function bySex($field_sex, $operator = NULL) {
    return $this->byFieldConditions(array('field_sex' => array($field_sex, $operator)));
  }

  /**
   * Order by field_sex
   *
   * @param string $direction
   *
   * @return $this
   */
  public function orderBySex($direction = 'ASC') {
    return $this->orderByField('field_sex.value', $direction);
  }

  /**
   * Query by field_date_naiss
   *
   * @param mixed $field_date_naiss
   * @param string $operator
   *
   * @return $this
   */
  public function byDateNaiss($field_date_naiss, $operator = NULL) {
    return $this->byFieldConditions(array('field_date_naiss' => array($field_date_naiss, $operator)));
  }

  /**
   * Order by field_date_naiss
   *
   * @param string $direction
   *
   * @return $this
   */
  public function orderByDateNaiss($direction = 'ASC') {
    return $this->orderByField('field_date_naiss.value', $direction);
  }

  /**
   * Query by field_biographie
   *
   * @param mixed $field_biographie
   * @param string $operator
   *
   * @return $this
   */
  public function byBiographie($field_biographie, $operator = NULL) {
    return $this->byFieldConditions(array('field_biographie' => array($field_biographie, $operator)));
  }

  /**
   * Order by field_biographie
   *
   * @param string $direction
   *
   * @return $this
   */
  public function orderByBiographie($direction = 'ASC') {
    return $this->orderByField('field_biographie.value', $direction);
  }

}
