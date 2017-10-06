<?php
/**
 * @file
 * class TypeDeNoteTaxonomyTermWrapperQuery
 */

class TypeDeNoteTaxonomyTermWrapperQueryResults extends WdTaxonomyTermWrapperQueryResults {

  /**
   * @return TypeDeNoteTaxonomyTermWrapper
   */
  public function current() {
    return parent::current();
  }
}

class TypeDeNoteTaxonomyTermWrapperQuery extends WdTaxonomyTermWrapperQuery {

  private static $bundle = 'type_de_note';

  /**
   * Construct a TypeDeNoteTaxonomyTermWrapperQuery
   */
  public function __construct() {
    parent::__construct('taxonomy_term');
    $this->byBundle(TypeDeNoteTaxonomyTermWrapperQuery::$bundle);
  }

  /**
   * Construct a TypeDeNoteTaxonomyTermWrapperQuery
   *
   * @return TypeDeNoteTaxonomyTermWrapperQuery
   */
  public static function find() {
    return new self();
  }

  /**
   * @return TypeDeNoteTaxonomyTermWrapperQueryResults
   */
  public function execute() {
    return new TypeDeNoteTaxonomyTermWrapperQueryResults($this->entityType, $this->query->execute());
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
