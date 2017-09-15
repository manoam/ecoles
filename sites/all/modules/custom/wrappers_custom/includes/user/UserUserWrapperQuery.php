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

}