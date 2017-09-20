<?php
/**
 * @file
 * class WdEleveWrapper
 */

class WdEleveWrapper extends WdEntityWrapper {

  protected $entity_type = 'eleve';

  /**
   * Create a new eleve.
   *
   * @param array $values
   * @param string $language
   *
   * @return WdEleveWrapper
   */
  public static function create($values = array(), $language = LANGUAGE_NONE) {
    $values += array('entity_type' => 'eleve');
    $entity_wrapper = parent::create($values, $language);
    return new WdEleveWrapper($entity_wrapper->value());
  }

  /**
   * Sets type
   *
   * @param string $value
   *
   * @return $this
   */
  public function setType($value) {
    $this->set('type', $value);
    return $this;
  }

  /**
   * Retrieves type
   *
   * @return string
   */
  public function getType() {
    return $this->getBundle();
  }

  /**
   * Sets title
   *
   * @param string $value
   *
   * @return $this
   */
  public function setTitle($value) {
    $this->set('title', $value);
    return $this;
  }

  /**
   * Retrieves title
   *
   * @return string
   */
  public function getTitle($format = WdEntityWrapper::FORMAT_PLAIN) {
    return $this->getText('title', $format);
  }

  /**
   * Sets uid
   *
   * @param int|object|WdUserWrapper $value
   *
   * @return $this
   */
  public function setUid($value) {
    if ($value instanceof WdEntityWrapper) {
      $value = $value->value();
    }
    $this->set('uid', $value);
    return $this;
  }

  /**
   * Retrieves uid
   *
   * @return WdUserWrapper
   */
  public function getUid() {
    $value = $this->get('uid');
    if (!empty($value)) {
      return new WdUserWrapper($value);
    }
    return NULL;
  }

  /**
   * Sets created
   *
   * @param int $value
   *
   * @return $this
   */
  public function setCreated($value) {
    $this->set('created', $value);
    return $this;
  }

  /**
   * Retrieves created
   *
   * @return int|string
   */
  public function getCreated($format = WdEntityWrapper::DATE_UNIX, $custom_format = NULL) {
    return $this->getDate('created', $format, $custom_format);
  }

  /**
   * Sets changed
   *
   * @param int $value
   *
   * @return $this
   */
  public function setChanged($value) {
    $this->set('changed', $value);
    return $this;
  }

  /**
   * Retrieves changed
   *
   * @return int|string
   */
  public function getChanged($format = WdEntityWrapper::DATE_UNIX, $custom_format = NULL) {
    return $this->getDate('changed', $format, $custom_format);
  }

}
