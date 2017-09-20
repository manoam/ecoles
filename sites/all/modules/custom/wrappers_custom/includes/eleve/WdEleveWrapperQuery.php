<?php
/**
 * @file
 * class WdEleveWrapperQuery
 */

class WdEleveWrapperQueryResults extends WdWrapperQueryResults {

  /**
   * @return WdEleveWrapper
   */
  public function current() {
    return parent::current();
  }
}

class WdEleveWrapperQuery extends WdWrapperQuery {

  /**
   * Construct a WdEleveWrapperQuery
   */
  public function __construct() {
    parent::__construct('eleve');
  }

  /**
   * Construct a WdEleveWrapperQuery
   *
   * @return WdEleveWrapperQuery
   */
  public static function find() {
    return new self();
  }

  /**
   * @return WdEleveWrapperQueryResults
   */
  public function execute() {
    return new WdEleveWrapperQueryResults($this->entityType, $this->query->execute());
  }

  /**
   * Query by type
   *
   * @param string $type
   * @param string $operator
   *
   * @return $this
   */
  public function byType($type, $operator = NULL) {
    return parent::byBundle($type, $operator);
  }

  /**
   * Order by type
   *
   * @param string $direction
   *
   * @return $this
   */
  public function orderByType($direction = 'ASC') {
    return $this->orderByProperty('type.value', $direction);
  }

  /**
   * Query by title
   *
   * @param string $title
   * @param string $operator
   *
   * @return $this
   */
  public function byTitle($title, $operator = NULL) {
    return $this->byPropertyConditions(array('title' => array($title, $operator)));
  }

  /**
   * Order by title
   *
   * @param string $direction
   *
   * @return $this
   */
  public function orderByTitle($direction = 'ASC') {
    return $this->orderByProperty('title', $direction);
  }

  /**
   * Query by uid
   *
   * @param int|object|WdUserWrapper $uid
   * @param string $operator
   *
   * @return $this
   */
  public function byUid($uid, $operator = NULL) {
    if ($uid instanceof WdEntityWrapper) {
      $id = $uid->getId();
    }
    elseif (is_object($uid)) {
      $wrapper = new WdUserWrapper($uid);
      $id = $wrapper->getId();
    }
    else {
      $id = $uid;
    }
    return $this->byPropertyConditions(array('uid' => array($id, $operator)));
  }

  /**
   * Order by uid
   *
   * @param string $direction
   *
   * @return $this
   */
  public function orderByUid($direction = 'ASC') {
    return $this->orderByProperty('uid', $direction);
  }

  /**
   * Query by created
   *
   * @param int $created
   * @param string $operator
   *
   * @return $this
   */
  public function byCreated($created, $operator = NULL) {
    return $this->byPropertyConditions(array('created' => array($created, $operator)));
  }

  /**
   * Order by created
   *
   * @param string $direction
   *
   * @return $this
   */
  public function orderByCreated($direction = 'ASC') {
    return $this->orderByProperty('created', $direction);
  }

  /**
   * Query by changed
   *
   * @param int $changed
   * @param string $operator
   *
   * @return $this
   */
  public function byChanged($changed, $operator = NULL) {
    return $this->byPropertyConditions(array('changed' => array($changed, $operator)));
  }

  /**
   * Order by changed
   *
   * @param string $direction
   *
   * @return $this
   */
  public function orderByChanged($direction = 'ASC') {
    return $this->orderByProperty('changed', $direction);
  }

}
