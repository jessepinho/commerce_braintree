<?php

/**
 * @file
 * Drush command file.
 */

function drush_commerce_braintree_post_sql_sync($source = NULL, $destination = NULL) {
  $settings = array();
  $rule = rules_config_load('commerce_payment_braintree');
  foreach ($rule->actions() as $action) {
    if (!empty($action->settings['payment_method']['settings']['environment'])) {
      $action->settings['payment_method']['settings']['environment'] = 'sandbox';
    }
  }
  entity_save('rules_config', $rule);
}
