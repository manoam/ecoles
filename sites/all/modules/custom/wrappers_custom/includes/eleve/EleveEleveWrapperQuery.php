<?php
/**
 * @file
 * class EleveEleveWrapperQuery
 */

class EleveEleveWrapperQueryResults extends WdEleveWrapperQueryResults {

  /**
   * @return EleveEleveWrapper
   */
  public function current() {
    return parent::current();
  }
}

class EleveEleveWrapperQuery extends WdEleveWrapperQuery {

  private static $bundle = 'eleve';

  /**
   * Construct a EleveEleveWrapperQuery
   */
  public function __construct() {
    parent::__construct('eleve');
    $this->byBundle(EleveEleveWrapperQuery::$bundle);
  }

  /**
   * Construct a EleveEleveWrapperQuery
   *
   * @return EleveEleveWrapperQuery
   */
  public static function find() {
    return new self();
  }

  /**
   * @return EleveEleveWrapperQueryResults
   */
  public function execute() {
    return new EleveEleveWrapperQueryResults($this->entityType, $this->query->execute());
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
   * Query by field_prenom
   *
   * @param mixed $field_prenom
   * @param string $operator
   *
   * @return $this
   */
  public function byPrenom($field_prenom, $operator = NULL) {
    return $this->byFieldConditions(array('field_prenom' => array($field_prenom, $operator)));
  }

  /**
   * Order by field_prenom
   *
   * @param string $direction
   *
   * @return $this
   */
  public function orderByPrenom($direction = 'ASC') {
    return $this->orderByField('field_prenom.value', $direction);
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
   * Query by field_num_mat
   *
   * @param mixed $field_num_mat
   * @param string $operator
   *
   * @return $this
   */
  public function byNumMat($field_num_mat, $operator = NULL) {
    return $this->byFieldConditions(array('field_num_mat' => array($field_num_mat, $operator)));
  }

  /**
   * Order by field_num_mat
   *
   * @param string $direction
   *
   * @return $this
   */
  public function orderByNumMat($direction = 'ASC') {
    return $this->orderByField('field_num_mat.value', $direction);
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
   * Query by field_nom_pere
   *
   * @param mixed $field_nom_pere
   * @param string $operator
   *
   * @return $this
   */
  public function byNomPere($field_nom_pere, $operator = NULL) {
    return $this->byFieldConditions(array('field_nom_pere' => array($field_nom_pere, $operator)));
  }

  /**
   * Order by field_nom_pere
   *
   * @param string $direction
   *
   * @return $this
   */
  public function orderByNomPere($direction = 'ASC') {
    return $this->orderByField('field_nom_pere.value', $direction);
  }

  /**
   * Query by field_profession_pere
   *
   * @param mixed $field_profession_pere
   * @param string $operator
   *
   * @return $this
   */
  public function byProfessionPere($field_profession_pere, $operator = NULL) {
    return $this->byFieldConditions(array('field_profession_pere' => array($field_profession_pere, $operator)));
  }

  /**
   * Order by field_profession_pere
   *
   * @param string $direction
   *
   * @return $this
   */
  public function orderByProfessionPere($direction = 'ASC') {
    return $this->orderByField('field_profession_pere.value', $direction);
  }

  /**
   * Query by field_nom_mere
   *
   * @param mixed $field_nom_mere
   * @param string $operator
   *
   * @return $this
   */
  public function byNomMere($field_nom_mere, $operator = NULL) {
    return $this->byFieldConditions(array('field_nom_mere' => array($field_nom_mere, $operator)));
  }

  /**
   * Order by field_nom_mere
   *
   * @param string $direction
   *
   * @return $this
   */
  public function orderByNomMere($direction = 'ASC') {
    return $this->orderByField('field_nom_mere.value', $direction);
  }

  /**
   * Query by field_profession_mere
   *
   * @param mixed $field_profession_mere
   * @param string $operator
   *
   * @return $this
   */
  public function byProfessionMere($field_profession_mere, $operator = NULL) {
    return $this->byFieldConditions(array('field_profession_mere' => array($field_profession_mere, $operator)));
  }

  /**
   * Order by field_profession_mere
   *
   * @param string $direction
   *
   * @return $this
   */
  public function orderByProfessionMere($direction = 'ASC') {
    return $this->orderByField('field_profession_mere.value', $direction);
  }

  /**
   * Query by field_photo
   *
   * @param mixed $field_photo
   * @param string $operator
   *
   * @return $this
   */
  public function byPhoto($field_photo, $operator = NULL) {
    if (is_object($field_photo) && !empty($field_photo->fid)) {
      $fid = $field_photo->fid;
    }
    elseif (is_array($field_photo) && !empty($field_photo['fid'])) {
      $fid = $field_photo['fid'];
    }
    else {
      $fid = $field_photo;
    }
    return $this->byFieldConditions(array('field_photo.fid' => array($field_photo, $operator)));
  }

  /**
   * Order by field_photo
   *
   * @param string $direction
   *
   * @return $this
   */
  public function orderByPhoto($direction = 'ASC') {
    return $this->orderByField('field_photo.fid', $direction);
  }

  /**
   * Query by field_mpiraitampoho
   *
   * @param mixed $field_mpiraitampoho
   * @param string $operator
   *
   * @return $this
   */
  public function byMpiraitampoho($field_mpiraitampoho, $operator = NULL) {
    if ($field_mpiraitampoho instanceof WdEntityWrapper) {
      $id = $field_mpiraitampoho->getIdentifier();
    }
    else {
      $id = $field_mpiraitampoho;
    }
    return $this->byFieldConditions(array('field_mpiraitampoho.target_id' => array($id, $operator)));
  }

  /**
   * Order by field_mpiraitampoho
   *
   * @param string $direction
   *
   * @return $this
   */
  public function orderByMpiraitampoho($direction = 'ASC') {
    return $this->orderByField('field_mpiraitampoho.target_id', $direction);
  }

  /**
   * Query by field_lieu
   *
   * @param mixed $field_lieu
   * @param string $operator
   *
   * @return $this
   */
  public function byLieu($field_lieu, $operator = NULL) {
    return $this->byFieldConditions(array('field_lieu' => array($field_lieu, $operator)));
  }

  /**
   * Order by field_lieu
   *
   * @param string $direction
   *
   * @return $this
   */
  public function orderByLieu($direction = 'ASC') {
    return $this->orderByField('field_lieu.value', $direction);
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

}
